/*
 * Copyright (C) 2019 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined(OGS_DIAMETER_INSIDE) && !defined(OGS_DIAMETER_COMPILATION)
#error "This header cannot be included directly."
#endif

#ifndef OGS_DIAM_S6A_DICT_H
#define OGS_DIAM_S6A_DICT_H

#ifdef __cplusplus
extern "C" {
#endif

#define OGS_DIAM_S6A_APPLICATION_ID                     16777251

#define OGS_DIAM_S6A_AVP_CODE_CONTEXT_IDENTIFIER        (1423)
#define OGS_DIAM_S6A_AVP_CODE_ALL_APN_CONFIG_INC_IND    (1428)
#define OGS_DIAM_S6A_AVP_CODE_APN_CONFIGURATION         (1430)
#define OGS_DIAM_S6A_AVP_CODE_MIP_HOME_AGENT_ADDRESS    (334)

#define OGS_DIAM_S6A_RAT_TYPE_WLAN                      0
#define OGS_DIAM_S6A_RAT_TYPE_VIRTUAL                   1
#define OGS_DIAM_S6A_RAT_TYPE_UTRAN                     1000
#define OGS_DIAM_S6A_RAT_TYPE_GERAN                     1001
#define OGS_DIAM_S6A_RAT_TYPE_GAN                       1002
#define OGS_DIAM_S6A_RAT_TYPE_HSPA_EVOLUTION            1003
#define OGS_DIAM_S6A_RAT_TYPE_EUTRAN                    1004
#define OGS_DIAM_S6A_RAT_TYPE_EUTRAN_NB_IOT             1005
#define OGS_DIAM_S6A_RAT_TYPE_CDMA2000_1X               2000
#define OGS_DIAM_S6A_RAT_TYPE_HRPD                      2001
#define OGS_DIAM_S6A_RAT_TYPE_UMB                       2002
#define OGS_DIAM_S6A_RAT_TYPE_EHRPD                     2003

#define OGS_DIAM_S6A_ULR_SINGLE_REGISTRATION_IND        (1)
#define OGS_DIAM_S6A_ULR_S6A_S6D_INDICATOR              (1 << 1)
#define OGS_DIAM_S6A_ULR_SKIP_SUBSCRIBER_DATA           (1 << 2)
#define OGS_DIAM_S6A_ULR_GPRS_SUBSCRIPTION_DATA_IND     (1 << 3)
#define OGS_DIAM_S6A_ULR_NODE_TYPE_IND                  (1 << 4)
#define OGS_DIAM_S6A_ULR_INITIAL_ATTACH_IND             (1 << 5)
#define OGS_DIAM_S6A_ULR_PS_LCS_SUPPORTED_BY_UE         (1 << 6)

#define OGS_DIAM_S6A_UE_SRVCC_NOT_SUPPORTED             (0)
#define OGS_DIAM_S6A_UE_SRVCC_SUPPORTED                 (1)

extern struct dict_object *ogs_diam_s6a_application;

extern struct dict_object *ogs_diam_s6a_cmd_air;
extern struct dict_object *ogs_diam_s6a_cmd_aia;
extern struct dict_object *ogs_diam_s6a_cmd_ulr;
extern struct dict_object *ogs_diam_s6a_cmd_ula;
extern struct dict_object *ogs_diam_s6a_cmd_pur;
extern struct dict_object *ogs_diam_s6a_cmd_pua;

extern struct dict_object *ogs_diam_s6a_visited_plmn_id;
extern struct dict_object *ogs_diam_s6a_rat_type;
extern struct dict_object *ogs_diam_s6a_ulr_flags;
extern struct dict_object *ogs_diam_s6a_ula_flags;
extern struct dict_object *ogs_diam_s6a_subscription_data;
extern struct dict_object *ogs_diam_s6a_req_eutran_auth_info;
extern struct dict_object *ogs_diam_s6a_number_of_requested_vectors;
extern struct dict_object *ogs_diam_s6a_immediate_response_preferred;
extern struct dict_object *ogs_diam_s6a_authentication_info;
extern struct dict_object *ogs_diam_s6a_re_synchronization_info;
extern struct dict_object *ogs_diam_s6a_service_selection;
extern struct dict_object *ogs_diam_s6a_ue_srvcc_capability;
extern struct dict_object *ogs_diam_s6a_e_utran_vector;
extern struct dict_object *ogs_diam_s6a_rand;
extern struct dict_object *ogs_diam_s6a_xres;
extern struct dict_object *ogs_diam_s6a_autn;
extern struct dict_object *ogs_diam_s6a_kasme;
extern struct dict_object *ogs_diam_s6a_subscriber_status;
extern struct dict_object *ogs_diam_s6a_ambr;
extern struct dict_object *ogs_diam_s6a_network_access_mode;
extern struct dict_object *ogs_diam_s6a_access_restriction_data;
extern struct dict_object *ogs_diam_s6a_apn_configuration_profile;
extern struct dict_object *ogs_diam_s6a_subscribed_rau_tau_timer;
extern struct dict_object *ogs_diam_s6a_context_identifier;
extern struct dict_object *ogs_diam_s6a_all_apn_configuration_included_indicator;
extern struct dict_object *ogs_diam_s6a_apn_configuration;
extern struct dict_object *ogs_diam_s6a_max_bandwidth_ul;
extern struct dict_object *ogs_diam_s6a_max_bandwidth_dl;
extern struct dict_object *ogs_diam_s6a_pdn_type;
extern struct dict_object *ogs_diam_s6a_eps_subscribed_qos_profile;
extern struct dict_object *ogs_diam_s6a_qos_class_identifier;
extern struct dict_object *ogs_diam_s6a_allocation_retention_priority;
extern struct dict_object *ogs_diam_s6a_priority_level;
extern struct dict_object *ogs_diam_s6a_pre_emption_capability;
extern struct dict_object *ogs_diam_s6a_pre_emption_vulnerability;

int ogs_diam_s6a_dict_init(void);

#ifdef __cplusplus
}
#endif

#endif /* OGS_DIAM_OGS_DIAM_S6A_DICT_H */
