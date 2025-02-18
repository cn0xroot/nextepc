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

#ifndef OGS_GTP_H
#define OGS_GTP_H

#include "ogs-common.h"

#define OGS_GTPV1_U_UDP_PORT            2152
#define OGS_GTPV2_C_UDP_PORT            2123

/* Num of PacketFilter per Bearer */
#define OGS_MAX_NUM_OF_PACKET_FILTER    16 

#define OGS_GTP_INSIDE

#include "gtp/message.h"
#include "gtp/types.h"
#include "gtp/conv.h"
#include "gtp/node.h"
#include "gtp/path.h"
#include "gtp/xact.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef OGS_GTP_INSIDE

extern int __ogs_gtp_domain;

#undef OGS_LOG_DOMAIN
#define OGS_LOG_DOMAIN __ogs_gtp_domain

#ifdef __cplusplus
}
#endif

#endif /* OGS_GTP_H */
