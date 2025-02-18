/**
 * @file main.c
 */

#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>

#include "ogs-app.h"

#define DEFAULT_CONFIG_FILENAME SYSCONF_DIR "nextepc/nextepc.conf"

static char *version = "NextEPC daemon v" PACKAGE_VERSION;

static void show_version()
{
    printf("%s\n\n", version);
}

static void show_help(const char *name)
{
    printf("Usage: %s [options]\n"
        "Options:\n"
       "   -c filename    : set configuration file\n"
       "   -l filename    : set logging file\n"
       "   -e level       : set global log-level (default:info)\n"
       "   -m domain      : set log-domain (e.g. mme:sgw:gtp)\n"
       "   -d             : print lots of debugging information\n"
       "   -t             : print tracing information for developer\n"
       "   -D             : start as a daemon\n"
       "   -v             : show version number and exit\n"
       "   -h             : show this message and exit\n"
       "\n", name);
}

static void show_running_config()
{
    ogs_log_print(OGS_LOG_INFO, "%s\n\n", version);

    ogs_info("Configuration: '%s'", ogs_config()->file);

    if (ogs_config()->logger.file) {
        ogs_info("File Logging: '%s'", ogs_config()->logger.file);

        if (ogs_config()->logger.level)
            ogs_info("LOG-LEVEL: '%s'", ogs_config()->logger.level);

        if (ogs_config()->logger.domain)
            ogs_info("LOG-DOMAIN: '%s'", ogs_config()->logger.domain);
    }
}

static int check_signal(int signum)
{
    switch (signum) {
    case SIGTERM:
    case SIGINT:
        ogs_info("%s received", 
                signum == SIGTERM ? "SIGTERM" : "SIGINT");

        return 1;
    case SIGHUP:
        ogs_info("SIGHUP received");
        ogs_log_cycle();

        break;
    default:
        ogs_error("Signal-NUM[%d] received (%s)",
                signum, ogs_signal_description_get(signum));
        break;
            
    }
    return 0;
}

static void terminate()
{
    app_terminate();

    ogs_app_terminate();
}

int main(int argc, char *argv[])
{
    /**************************************************************************
     * Starting up process.
     *
     * Keep the order of starting-up
     */
    int rv, i, opt;
    ogs_getopt_t options;
    struct {
        char *config_file;
        char *log_file;
        char *log_level;
        char *domain_mask;

        bool enable_debug;
        bool enable_trace;
    } optarg;
    char *argv_out[argc];

    memset(&optarg, 0, sizeof(optarg));

    ogs_getopt_init(&options, argv);
    while ((opt = ogs_getopt(&options, "vhDc:l:e:m:dt")) != -1) {
        switch (opt) {
        case 'v':
            show_version();
            return OGS_OK;
        case 'h':
            show_help(argv[0]);
            return OGS_OK;
        case 'D':
#if !defined(_WIN32)
        {
            pid_t pid;
            pid = fork();

            ogs_assert(pid >= 0);

            if (pid != 0)
            {
                /* Parent */
                return EXIT_SUCCESS;
            }
            /* Child */

            setsid();
            umask(027);
        }
#else
            printf("%s: Not Support in WINDOWS", argv[0]);
#endif
            break;
        case 'c':
            optarg.config_file = options.optarg;
            break;
        case 'l':
            optarg.log_file = options.optarg;
            break;
        case 'e':
            optarg.log_level = options.optarg;
            break;
        case 'm':
            optarg.domain_mask = options.optarg;
            break;
        case 'd':
            optarg.enable_debug = true;
            break;
        case 't':
            optarg.enable_trace = true;
            break;
        case '?':
            fprintf(stderr, "%s: %s\n", argv[0], options.errmsg);
            show_help(argv[0]);
            return OGS_ERROR;
        default:
            fprintf(stderr, "%s: should not be reached\n", OGS_FUNC);
            return OGS_ERROR;
        }
    }

    if (optarg.enable_debug) optarg.log_level = "debug";
    if (optarg.enable_trace) optarg.log_level = "trace";

    i = 0;
    argv_out[i++] = argv[0];

    if (optarg.config_file) {
        argv_out[i++] = "-c";
        argv_out[i++] = optarg.config_file;
    }
    if (optarg.log_file) {
        argv_out[i++] = "-l";
        argv_out[i++] = optarg.log_file;
    }
    if (optarg.log_level) {
        argv_out[i++] = "-e";
        argv_out[i++] = optarg.log_level;
    }
    if (optarg.domain_mask) {
        argv_out[i++] = "-m";
        argv_out[i++] = optarg.domain_mask;
    }

    argv_out[i] = NULL;

    ogs_signal_init();
    ogs_setup_signal_thread();

    rv = ogs_app_initialize(DEFAULT_CONFIG_FILENAME, argv_out);
    ogs_assert(rv == OGS_OK);

    show_running_config();

    rv = app_initialize(argv_out);
    if (rv != OGS_OK) {
        if (rv == OGS_RETRY)
            return EXIT_SUCCESS;

        ogs_fatal("NextEPC initialization failed. Aborted");
        return OGS_ERROR;
    }

    atexit(terminate);
    ogs_signal_thread(check_signal);

    ogs_info("NextEPC daemon terminating...");

    return OGS_OK;
}

