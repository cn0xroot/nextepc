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

/*******************************************************************************
 * This file had been created by gtp-tlv.py script v0.1.0
 * Please do not modify this file but regenerate it via script.
 * Created on: 2019-09-10 21:31:45.116236 by acetcom
 * from 29274-d80.docx
 ******************************************************************************/

#if !defined(OGS_GTP_INSIDE) && !defined(OGS_GTP_COMPILATION)
#error "This header cannot be included directly."
#endif

#ifndef OGS_GTP_MESSAGE_H
#define OGS_GTP_MESSAGE_H

#include "tlv.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 5.1 General format */
#define OGS_GTPV1U_HEADER_LEN   8
#define OGS_GTPV2C_HEADER_LEN   12
#define OGS_GTP_TEID_LEN        4
typedef struct ogs_gtp_header_s {
    union {
        struct {
        ED4(uint8_t version:3;,
            uint8_t piggybacked:1;,
            uint8_t teid_presence:1;,
            uint8_t spare1:3;)
        };
/* GTU-U flags */
#define OGS_GTPU_FLAGS_PN                       0x1
#define OGS_GTPU_FLAGS_S                        0x2
        uint8_t flags;
    };
    uint8_t type;
    uint16_t length;
    union {
        struct {
            uint32_t teid;
            /* sqn : 31bit ~ 8bit, spare : 7bit ~ 0bit */
#define OGS_GTP_XID_TO_SQN(__xid) htonl(((__xid) << 8))
#define OGS_GTP_SQN_TO_XID(__sqn) (ntohl(__sqn) >> 8)
            uint32_t sqn;
        };
        /* sqn : 31bit ~ 8bit, spare : 7bit ~ 0bit */
        uint32_t sqn_only;
    };
} __attribute__ ((packed)) ogs_gtp_header_t;

/* GTP-U message type, defined in 3GPP TS 29.281 Release 11 */
#define OGS_GTPU_MSGTYPE_ECHO_REQ               1
#define OGS_GTPU_MSGTYPE_ECHO_RSP               2
#define OGS_GTPU_MSGTYPE_ERR_IND                26
#define OGS_GTPU_MSGTYPE_SUPP_EXTHDR_NOTI       31
#define OGS_GTPU_MSGTYPE_END_MARKER             254
#define OGS_GTPU_MSGTYPE_GPDU                   255

/* GTPv2-C message type */
#define OGS_GTP_ECHO_REQUEST_TYPE 1
#define OGS_GTP_ECHO_RESPONSE_TYPE 2
#define OGS_GTP_VERSION_NOT_SUPPORTED_INDICATION_TYPE 3
#define OGS_GTP_CREATE_SESSION_REQUEST_TYPE 32
#define OGS_GTP_CREATE_SESSION_RESPONSE_TYPE 33
#define OGS_GTP_MODIFY_BEARER_REQUEST_TYPE 34
#define OGS_GTP_MODIFY_BEARER_RESPONSE_TYPE 35
#define OGS_GTP_DELETE_SESSION_REQUEST_TYPE 36
#define OGS_GTP_DELETE_SESSION_RESPONSE_TYPE 37
#define OGS_GTP_CHANGE_NOTIFICATION_REQUEST_TYPE 38
#define OGS_GTP_CHANGE_NOTIFICATION_RESPONSE_TYPE 39
#define OGS_GTP_REMOTE_UE_REPORT_NOTIFICATION_TYPE 40
#define OGS_GTP_REMOTE_UE_REPORT_ACKNOWLEDGE_TYPE 41
#define OGS_GTP_MODIFY_BEARER_COMMAND_TYPE 64
#define OGS_GTP_MODIFY_BEARER_FAILURE_INDICATION_TYPE 65
#define OGS_GTP_DELETE_BEARER_COMMAND_TYPE 66
#define OGS_GTP_DELETE_BEARER_FAILURE_INDICATION_TYPE 67
#define OGS_GTP_BEARER_RESOURCE_COMMAND_TYPE 68
#define OGS_GTP_BEARER_RESOURCE_FAILURE_INDICATION_TYPE 69
#define OGS_GTP_DOWNLINK_DATA_NOTIFICATION_FAILURE_INDICATION_TYPE 70
#define OGS_GTP_TRACE_SESSION_ACTIVATION_TYPE 71
#define OGS_GTP_TRACE_SESSION_DEACTIVATION_TYPE 72
#define OGS_GTP_STOP_PAGING_INDICATION_TYPE 73
#define OGS_GTP_CREATE_BEARER_REQUEST_TYPE 95
#define OGS_GTP_CREATE_BEARER_RESPONSE_TYPE 96
#define OGS_GTP_UPDATE_BEARER_REQUEST_TYPE 97
#define OGS_GTP_UPDATE_BEARER_RESPONSE_TYPE 98
#define OGS_GTP_DELETE_BEARER_REQUEST_TYPE 99
#define OGS_GTP_DELETE_BEARER_RESPONSE_TYPE 100
#define OGS_GTP_DELETE_PDN_CONNECTION_SET_REQUEST_TYPE 101
#define OGS_GTP_DELETE_PDN_CONNECTION_SET_RESPONSE_TYPE 102
#define OGS_GTP_PGW_DOWNLINK_TRIGGERING_NOTIFICATION_TYPE 103
#define OGS_GTP_PGW_DOWNLINK_TRIGGERING_ACKNOWLEDGE_TYPE 104
#define OGS_GTP_CREATE_FORWARDING_TUNNEL_REQUEST_TYPE 160
#define OGS_GTP_CREATE_FORWARDING_TUNNEL_RESPONSE_TYPE 161
#define OGS_GTP_SUSPEND_NOTIFICATION_TYPE 162
#define OGS_GTP_SUSPEND_ACKNOWLEDGE_TYPE 163
#define OGS_GTP_RESUME_NOTIFICATION_TYPE 164
#define OGS_GTP_RESUME_ACKNOWLEDGE_TYPE 165
#define OGS_GTP_CREATE_INDIRECT_DATA_FORWARDING_TUNNEL_REQUEST_TYPE 166
#define OGS_GTP_CREATE_INDIRECT_DATA_FORWARDING_TUNNEL_RESPONSE_TYPE 167
#define OGS_GTP_DELETE_INDIRECT_DATA_FORWARDING_TUNNEL_REQUEST_TYPE 168
#define OGS_GTP_DELETE_INDIRECT_DATA_FORWARDING_TUNNEL_RESPONSE_TYPE 169
#define OGS_GTP_RELEASE_ACCESS_BEARERS_REQUEST_TYPE 170
#define OGS_GTP_RELEASE_ACCESS_BEARERS_RESPONSE_TYPE 171
#define OGS_GTP_DOWNLINK_DATA_NOTIFICATION_TYPE 176
#define OGS_GTP_DOWNLINK_DATA_NOTIFICATION_ACKNOWLEDGE_TYPE 177
#define OGS_GTP_PGW_RESTART_NOTIFICATION_TYPE 179
#define OGS_GTP_PGW_RESTART_NOTIFICATION_ACKNOWLEDGE_TYPE 180
#define OGS_GTP_UPDATE_PDN_CONNECTION_SET_REQUEST_TYPE 200
#define OGS_GTP_UPDATE_PDN_CONNECTION_SET_RESPONSE_TYPE 201
#define OGS_GTP_MODIFY_ACCESS_BEARERS_REQUEST_TYPE 211
#define OGS_GTP_MODIFY_ACCESS_BEARERS_RESPONSE_TYPE 212

#define OGS_TLV_IMSI_TYPE 1
#define OGS_TLV_CAUSE_TYPE 2
#define OGS_TLV_RECOVERY_TYPE 3
#define OGS_TLV_STN_SR_TYPE 51
#define OGS_TLV_APN_TYPE 71
#define OGS_TLV_AMBR_TYPE 72
#define OGS_TLV_EBI_TYPE 73
#define OGS_TLV_IP_ADDRESS_TYPE 74
#define OGS_TLV_MEI_TYPE 75
#define OGS_TLV_MSISDN_TYPE 76
#define OGS_TLV_INDICATION_TYPE 77
#define OGS_TLV_PCO_TYPE 78
#define OGS_TLV_PAA_TYPE 79
#define OGS_TLV_BEARER_QOS_TYPE 80
#define OGS_TLV_FLOW_QOS_TYPE 81
#define OGS_TLV_RAT_TYPE_TYPE 82
#define OGS_TLV_SERVING_NETWORK_TYPE 83
#define OGS_TLV_BEARER_TFT_TYPE 84
#define OGS_TLV_TAD_TYPE 85
#define OGS_TLV_ULI_TYPE 86
#define OGS_TLV_F_TEID_TYPE 87
#define OGS_TLV_TMSI_TYPE 88
#define OGS_TLV_GLOBAL_CN_ID_TYPE 89
#define OGS_TLV_S103PDF_TYPE 90
#define OGS_TLV_S1UDF_TYPE 91
#define OGS_TLV_DELAY_VALUE_TYPE 92
#define OGS_TLV_BEARER_CONTEXT_TYPE 93
#define OGS_TLV_CHARGING_ID_TYPE 94
#define OGS_TLV_CHARGING_CHARACTERISTICS_TYPE 95
#define OGS_TLV_TRACE_INFORMATION_TYPE 96
#define OGS_TLV_BEARER_FLAGS_TYPE 97
#define OGS_TLV_PDN_TYPE_TYPE 99
#define OGS_TLV_PTI_TYPE 100
#define OGS_TLV_MM_CONTEXT_TYPE 107
#define OGS_TLV_PDN_CONNECTION_TYPE 109
#define OGS_TLV_PDU_NUMBERS_TYPE 110
#define OGS_TLV_P_TMSI_TYPE 111
#define OGS_TLV_P_TMSI_SIGNATURE_TYPE 112
#define OGS_TLV_HOP_COUNTER_TYPE 113
#define OGS_TLV_UE_TIME_ZONE_TYPE 114
#define OGS_TLV_TRACE_REFERENCE_TYPE 115
#define OGS_TLV_COMPLETE_REQUEST_MESSAGE_TYPE 116
#define OGS_TLV_GUTI_TYPE 117
#define OGS_TLV_F_CONTAINER_TYPE 118
#define OGS_TLV_F_CAUSE_TYPE 119
#define OGS_TLV_PLMN_ID_TYPE 120
#define OGS_TLV_TARGET_IDENTIFICATION_TYPE 121
#define OGS_TLV_PACKET_FLOW_ID_TYPE 123
#define OGS_TLV_RAB_CONTEXT_TYPE 124
#define OGS_TLV_SOURCE_RNC_PDCP_CONTEXT_INFO_TYPE 125
#define OGS_TLV_PORT_NUMBER_TYPE 126
#define OGS_TLV_APN_RESTRICTION_TYPE 127
#define OGS_TLV_SELECTION_MODE_TYPE 128
#define OGS_TLV_SOURCE_IDENTIFICATION_TYPE 129
#define OGS_TLV_CHANGE_REPORTING_ACTION_TYPE 131
#define OGS_TLV_FQ_CSID_TYPE 132
#define OGS_TLV_CHANNEL_NEEDED_TYPE 133
#define OGS_TLV_EMLPP_PRIORITY_TYPE 134
#define OGS_TLV_NODE_TYPE_TYPE 135
#define OGS_TLV_FQDN_TYPE 136
#define OGS_TLV_TI_TYPE 137
#define OGS_TLV_MBMS_SESSION_DURATION_TYPE 138
#define OGS_TLV_MBMS_SERVICE_AREA_TYPE 139
#define OGS_TLV_MBMS_SESSION_IDENTIFIER_TYPE 140
#define OGS_TLV_MBMS_FLOW_IDENTIFIER_TYPE 141
#define OGS_TLV_MBMS_IP_MULTICAST_DISTRIBUTION_TYPE 142
#define OGS_TLV_MBMS_DISTRIBUTION_ACKNOWLEDGE_TYPE 143
#define OGS_TLV_RFSP_INDEX_TYPE 144
#define OGS_TLV_UCI_TYPE 145
#define OGS_TLV_CSG_INFORMATION_REPORTING_ACTION_TYPE 146
#define OGS_TLV_CSG_ID_TYPE 147
#define OGS_TLV_CMI_TYPE 148
#define OGS_TLV_SERVICE_INDICATOR_TYPE 149
#define OGS_TLV_DETACH_TYPE_TYPE 150
#define OGS_TLV_LDN_TYPE 151
#define OGS_TLV_NODE_FEATURES_TYPE 152
#define OGS_TLV_MBMS_TIME_TO_DATA_TRANSFER_TYPE 153
#define OGS_TLV_THROTTLING_TYPE 154
#define OGS_TLV_ARP_TYPE 155
#define OGS_TLV_EPC_TIMER_TYPE 156
#define OGS_TLV_SIGNALLING_PRIORITY_INDICATION_TYPE 157
#define OGS_TLV_TMGI_TYPE 158
#define OGS_TLV_ADDITIONAL_MM_CONTEXT_FOR_SRVCC_TYPE 159
#define OGS_TLV_ADDITIONAL_FLAGS_FOR_SRVCC_TYPE 160
#define OGS_TLV_MDT_CONFIGURATION_TYPE 162
#define OGS_TLV_APCO_TYPE 163
#define OGS_TLV_ABSOLUTE_TIME_OF_MBMS_DATA_TRANSFER_TYPE 164
#define OGS_TLV_ENB_INFORMATION_REPORTING_TYPE 165
#define OGS_TLV_IP4CP_TYPE 166
#define OGS_TLV_CHANGE_TO_REPORT_FLAGS_TYPE 167
#define OGS_TLV_ACTION_INDICATION_TYPE 168
#define OGS_TLV_TWAN_IDENTIFIER_TYPE 169
#define OGS_TLV_ULI_TIMESTAMP_TYPE 170
#define OGS_TLV_MBMS_FLAGS_TYPE 171
#define OGS_TLV_RAN_NAS_CAUSE_TYPE 172
#define OGS_TLV_CN_OPERATOR_SELECTION_ENTITY_TYPE 173
#define OGS_TLV_TWMI_TYPE 174
#define OGS_TLV_NODE_NUMBER_TYPE 175
#define OGS_TLV_NODE_IDENTIFIER_TYPE 176
#define OGS_TLV_PRESENCE_REPORTING_AREA_ACTION_TYPE 177
#define OGS_TLV_PRESENCE_REPORTING_AREA_INFORMATION_TYPE 178
#define OGS_TLV_TWAN_IDENTIFIER_TIMESTAMP_TYPE 179
#define OGS_TLV_OVERLOAD_CONTROL_INFORMATION_TYPE 180
#define OGS_TLV_LOAD_CONTROL_INFORMATION_TYPE 181
#define OGS_TLV_METRIC_TYPE 182
#define OGS_TLV_SEQUENCE_NUMBER_TYPE 183
#define OGS_TLV_APN_AND_RELATIVE_CAPACITY_TYPE 184
#define OGS_TLV_WLAN_OFFLOADABILITY_INDICATION_TYPE 185
#define OGS_TLV_PAGING_AND_SERVICE_INFORMATION_TYPE 186
#define OGS_TLV_INTEGER_NUMBER_TYPE 187
#define OGS_TLV_MILLISECOND_TIME_STAMP_TYPE 188
#define OGS_TLV_MONITORING_EVENT_INFORMATION_TYPE 189
#define OGS_TLV_ECGI_LIST_TYPE 190
#define OGS_TLV_REMOTE_UE_CONTEXT_TYPE 191
#define OGS_TLV_REMOTE_USER_ID_TYPE 192
#define OGS_TLV_REMOTE_UE_IP_INFORMATION_TYPE 193
#define OGS_TLV_CIOT_OPTIMIZATIONS_SUPPORT_INDICATION_TYPE 194
#define OGS_TLV_SCEF_PDN_CONNECTION_TYPE 195
#define OGS_TLV_HEADER_COMPRESSION_CONFIGURATION_TYPE 196
#define OGS_TLV_EPCO_TYPE 197
#define OGS_TLV_SERVING_PLMN_RATE_CONTROL_TYPE 198
#define OGS_TLV_COUNTER_TYPE 199

/* Infomration Element TLV Descriptor */
extern ogs_tlv_desc_t ogs_tlv_desc_imsi_0;
extern ogs_tlv_desc_t ogs_tlv_desc_cause_0;
extern ogs_tlv_desc_t ogs_tlv_desc_recovery_0;
extern ogs_tlv_desc_t ogs_tlv_desc_stn_sr_0;
extern ogs_tlv_desc_t ogs_tlv_desc_apn_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ambr_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ebi_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ebi_1;
extern ogs_tlv_desc_t ogs_tlv_desc_ip_address_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ip_address_1;
extern ogs_tlv_desc_t ogs_tlv_desc_ip_address_2;
extern ogs_tlv_desc_t ogs_tlv_desc_ip_address_3;
extern ogs_tlv_desc_t ogs_tlv_desc_mei_0;
extern ogs_tlv_desc_t ogs_tlv_desc_msisdn_0;
extern ogs_tlv_desc_t ogs_tlv_desc_indication_0;
extern ogs_tlv_desc_t ogs_tlv_desc_pco_0;
extern ogs_tlv_desc_t ogs_tlv_desc_paa_0;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_qos_0;
extern ogs_tlv_desc_t ogs_tlv_desc_flow_qos_0;
extern ogs_tlv_desc_t ogs_tlv_desc_rat_type_0;
extern ogs_tlv_desc_t ogs_tlv_desc_serving_network_0;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_tft_0;
extern ogs_tlv_desc_t ogs_tlv_desc_tad_0;
extern ogs_tlv_desc_t ogs_tlv_desc_uli_0;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_0;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_1;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_2;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_3;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_4;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_5;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_6;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_7;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_8;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_9;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_10;
extern ogs_tlv_desc_t ogs_tlv_desc_f_teid_11;
extern ogs_tlv_desc_t ogs_tlv_desc_tmsi_0;
extern ogs_tlv_desc_t ogs_tlv_desc_global_cn_id_0;
extern ogs_tlv_desc_t ogs_tlv_desc_s103pdf_0;
extern ogs_tlv_desc_t ogs_tlv_desc_s1udf_0;
extern ogs_tlv_desc_t ogs_tlv_desc_delay_value_0;
extern ogs_tlv_desc_t ogs_tlv_desc_charging_id_0;
extern ogs_tlv_desc_t ogs_tlv_desc_charging_characteristics_0;
extern ogs_tlv_desc_t ogs_tlv_desc_trace_information_0;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_flags_0;
extern ogs_tlv_desc_t ogs_tlv_desc_pdn_type_0;
extern ogs_tlv_desc_t ogs_tlv_desc_pti_0;
extern ogs_tlv_desc_t ogs_tlv_desc_mm_context_0;
extern ogs_tlv_desc_t ogs_tlv_desc_pdu_numbers_0;
extern ogs_tlv_desc_t ogs_tlv_desc_p_tmsi_0;
extern ogs_tlv_desc_t ogs_tlv_desc_p_tmsi_signature_0;
extern ogs_tlv_desc_t ogs_tlv_desc_hop_counter_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ue_time_zone_0;
extern ogs_tlv_desc_t ogs_tlv_desc_trace_reference_0;
extern ogs_tlv_desc_t ogs_tlv_desc_complete_request_message_0;
extern ogs_tlv_desc_t ogs_tlv_desc_guti_0;
extern ogs_tlv_desc_t ogs_tlv_desc_f_container_0;
extern ogs_tlv_desc_t ogs_tlv_desc_f_cause_0;
extern ogs_tlv_desc_t ogs_tlv_desc_plmn_id_0;
extern ogs_tlv_desc_t ogs_tlv_desc_target_identification_0;
extern ogs_tlv_desc_t ogs_tlv_desc_packet_flow_id_0;
extern ogs_tlv_desc_t ogs_tlv_desc_rab_context_0;
extern ogs_tlv_desc_t ogs_tlv_desc_source_rnc_pdcp_context_info_0;
extern ogs_tlv_desc_t ogs_tlv_desc_port_number_0;
extern ogs_tlv_desc_t ogs_tlv_desc_port_number_1;
extern ogs_tlv_desc_t ogs_tlv_desc_port_number_2;
extern ogs_tlv_desc_t ogs_tlv_desc_apn_restriction_0;
extern ogs_tlv_desc_t ogs_tlv_desc_selection_mode_0;
extern ogs_tlv_desc_t ogs_tlv_desc_source_identification_0;
extern ogs_tlv_desc_t ogs_tlv_desc_change_reporting_action_0;
extern ogs_tlv_desc_t ogs_tlv_desc_fq_csid_0;
extern ogs_tlv_desc_t ogs_tlv_desc_fq_csid_1;
extern ogs_tlv_desc_t ogs_tlv_desc_fq_csid_2;
extern ogs_tlv_desc_t ogs_tlv_desc_fq_csid_3;
extern ogs_tlv_desc_t ogs_tlv_desc_channel_needed_0;
extern ogs_tlv_desc_t ogs_tlv_desc_emlpp_priority_0;
extern ogs_tlv_desc_t ogs_tlv_desc_node_type_0;
extern ogs_tlv_desc_t ogs_tlv_desc_fqdn_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ti_0;
extern ogs_tlv_desc_t ogs_tlv_desc_mbms_session_duration_0;
extern ogs_tlv_desc_t ogs_tlv_desc_mbms_service_area_0;
extern ogs_tlv_desc_t ogs_tlv_desc_mbms_session_identifier_0;
extern ogs_tlv_desc_t ogs_tlv_desc_mbms_flow_identifier_0;
extern ogs_tlv_desc_t ogs_tlv_desc_mbms_ip_multicast_distribution_0;
extern ogs_tlv_desc_t ogs_tlv_desc_mbms_distribution_acknowledge_0;
extern ogs_tlv_desc_t ogs_tlv_desc_rfsp_index_0;
extern ogs_tlv_desc_t ogs_tlv_desc_uci_0;
extern ogs_tlv_desc_t ogs_tlv_desc_csg_information_reporting_action_0;
extern ogs_tlv_desc_t ogs_tlv_desc_csg_id_0;
extern ogs_tlv_desc_t ogs_tlv_desc_cmi_0;
extern ogs_tlv_desc_t ogs_tlv_desc_service_indicator_0;
extern ogs_tlv_desc_t ogs_tlv_desc_detach_type_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ldn_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ldn_1;
extern ogs_tlv_desc_t ogs_tlv_desc_ldn_2;
extern ogs_tlv_desc_t ogs_tlv_desc_ldn_3;
extern ogs_tlv_desc_t ogs_tlv_desc_node_features_0;
extern ogs_tlv_desc_t ogs_tlv_desc_mbms_time_to_data_transfer_0;
extern ogs_tlv_desc_t ogs_tlv_desc_throttling_0;
extern ogs_tlv_desc_t ogs_tlv_desc_arp_0;
extern ogs_tlv_desc_t ogs_tlv_desc_epc_timer_0;
extern ogs_tlv_desc_t ogs_tlv_desc_signalling_priority_indication_0;
extern ogs_tlv_desc_t ogs_tlv_desc_tmgi_0;
extern ogs_tlv_desc_t ogs_tlv_desc_additional_mm_context_for_srvcc_0;
extern ogs_tlv_desc_t ogs_tlv_desc_additional_flags_for_srvcc_0;
extern ogs_tlv_desc_t ogs_tlv_desc_mdt_configuration_0;
extern ogs_tlv_desc_t ogs_tlv_desc_apco_0;
extern ogs_tlv_desc_t ogs_tlv_desc_absolute_time_of_mbms_data_transfer_0;
extern ogs_tlv_desc_t ogs_tlv_desc_enb_information_reporting_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ip4cp_0;
extern ogs_tlv_desc_t ogs_tlv_desc_change_to_report_flags_0;
extern ogs_tlv_desc_t ogs_tlv_desc_action_indication_0;
extern ogs_tlv_desc_t ogs_tlv_desc_twan_identifier_0;
extern ogs_tlv_desc_t ogs_tlv_desc_twan_identifier_1;
extern ogs_tlv_desc_t ogs_tlv_desc_uli_timestamp_0;
extern ogs_tlv_desc_t ogs_tlv_desc_mbms_flags_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ran_nas_cause_0;
extern ogs_tlv_desc_t ogs_tlv_desc_cn_operator_selection_entity_0;
extern ogs_tlv_desc_t ogs_tlv_desc_twmi_0;
extern ogs_tlv_desc_t ogs_tlv_desc_node_number_0;
extern ogs_tlv_desc_t ogs_tlv_desc_node_identifier_0;
extern ogs_tlv_desc_t ogs_tlv_desc_presence_reporting_area_action_0;
extern ogs_tlv_desc_t ogs_tlv_desc_presence_reporting_area_information_0;
extern ogs_tlv_desc_t ogs_tlv_desc_twan_identifier_timestamp_0;
extern ogs_tlv_desc_t ogs_tlv_desc_twan_identifier_timestamp_1;
extern ogs_tlv_desc_t ogs_tlv_desc_metric_0;
extern ogs_tlv_desc_t ogs_tlv_desc_sequence_number_0;
extern ogs_tlv_desc_t ogs_tlv_desc_apn_and_relative_capacity_0;
extern ogs_tlv_desc_t ogs_tlv_desc_wlan_offloadability_indication_0;
extern ogs_tlv_desc_t ogs_tlv_desc_paging_and_service_information_0;
extern ogs_tlv_desc_t ogs_tlv_desc_integer_number_0;
extern ogs_tlv_desc_t ogs_tlv_desc_millisecond_time_stamp_0;
extern ogs_tlv_desc_t ogs_tlv_desc_monitoring_event_information_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ecgi_list_0;
extern ogs_tlv_desc_t ogs_tlv_desc_remote_user_id_0;
extern ogs_tlv_desc_t ogs_tlv_desc_remote_ue_ip_information_0;
extern ogs_tlv_desc_t ogs_tlv_desc_ciot_optimizations_support_indication_0;
extern ogs_tlv_desc_t ogs_tlv_desc_header_compression_configuration_0;
extern ogs_tlv_desc_t ogs_tlv_desc_epco_0;
extern ogs_tlv_desc_t ogs_tlv_desc_serving_plmn_rate_control_0;
extern ogs_tlv_desc_t ogs_tlv_desc_counter_0;

/* Group Infomration Element TLV Descriptor */
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_context_0;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_context_1;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_context_2;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_context_3;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_context_4;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_context_5;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_context_6;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_context_7;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_context_8;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_context_9;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_context_10;
extern ogs_tlv_desc_t ogs_tlv_desc_pdn_connection_0;
extern ogs_tlv_desc_t ogs_tlv_desc_overload_control_information_0;
extern ogs_tlv_desc_t ogs_tlv_desc_overload_control_information_1;
extern ogs_tlv_desc_t ogs_tlv_desc_overload_control_information_2;
extern ogs_tlv_desc_t ogs_tlv_desc_load_control_information_0;
extern ogs_tlv_desc_t ogs_tlv_desc_load_control_information_1;
extern ogs_tlv_desc_t ogs_tlv_desc_load_control_information_2;
extern ogs_tlv_desc_t ogs_tlv_desc_remote_ue_context_0;
extern ogs_tlv_desc_t ogs_tlv_desc_scef_pdn_connection_0;

/* Message Descriptor */
extern ogs_tlv_desc_t ogs_tlv_desc_echo_request;
extern ogs_tlv_desc_t ogs_tlv_desc_echo_response;
extern ogs_tlv_desc_t ogs_tlv_desc_version_not_supported_indication;
extern ogs_tlv_desc_t ogs_tlv_desc_create_session_request;
extern ogs_tlv_desc_t ogs_tlv_desc_create_session_response;
extern ogs_tlv_desc_t ogs_tlv_desc_modify_bearer_request;
extern ogs_tlv_desc_t ogs_tlv_desc_modify_bearer_response;
extern ogs_tlv_desc_t ogs_tlv_desc_delete_session_request;
extern ogs_tlv_desc_t ogs_tlv_desc_delete_session_response;
extern ogs_tlv_desc_t ogs_tlv_desc_change_notification_request;
extern ogs_tlv_desc_t ogs_tlv_desc_change_notification_response;
extern ogs_tlv_desc_t ogs_tlv_desc_remote_ue_report_notification;
extern ogs_tlv_desc_t ogs_tlv_desc_remote_ue_report_acknowledge;
extern ogs_tlv_desc_t ogs_tlv_desc_modify_bearer_command;
extern ogs_tlv_desc_t ogs_tlv_desc_modify_bearer_failure_indication;
extern ogs_tlv_desc_t ogs_tlv_desc_delete_bearer_command;
extern ogs_tlv_desc_t ogs_tlv_desc_delete_bearer_failure_indication;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_resource_command;
extern ogs_tlv_desc_t ogs_tlv_desc_bearer_resource_failure_indication;
extern ogs_tlv_desc_t ogs_tlv_desc_downlink_data_notification_failure_indication;
extern ogs_tlv_desc_t ogs_tlv_desc_trace_session_activation;
extern ogs_tlv_desc_t ogs_tlv_desc_trace_session_deactivation;
extern ogs_tlv_desc_t ogs_tlv_desc_stop_paging_indication;
extern ogs_tlv_desc_t ogs_tlv_desc_create_bearer_request;
extern ogs_tlv_desc_t ogs_tlv_desc_create_bearer_response;
extern ogs_tlv_desc_t ogs_tlv_desc_update_bearer_request;
extern ogs_tlv_desc_t ogs_tlv_desc_update_bearer_response;
extern ogs_tlv_desc_t ogs_tlv_desc_delete_bearer_request;
extern ogs_tlv_desc_t ogs_tlv_desc_delete_bearer_response;
extern ogs_tlv_desc_t ogs_tlv_desc_delete_pdn_connection_set_request;
extern ogs_tlv_desc_t ogs_tlv_desc_delete_pdn_connection_set_response;
extern ogs_tlv_desc_t ogs_tlv_desc_pgw_downlink_triggering_notification;
extern ogs_tlv_desc_t ogs_tlv_desc_pgw_downlink_triggering_acknowledge;
extern ogs_tlv_desc_t ogs_tlv_desc_create_forwarding_tunnel_request;
extern ogs_tlv_desc_t ogs_tlv_desc_create_forwarding_tunnel_response;
extern ogs_tlv_desc_t ogs_tlv_desc_suspend_notification;
extern ogs_tlv_desc_t ogs_tlv_desc_suspend_acknowledge;
extern ogs_tlv_desc_t ogs_tlv_desc_resume_notification;
extern ogs_tlv_desc_t ogs_tlv_desc_resume_acknowledge;
extern ogs_tlv_desc_t ogs_tlv_desc_create_indirect_data_forwarding_tunnel_request;
extern ogs_tlv_desc_t ogs_tlv_desc_create_indirect_data_forwarding_tunnel_response;
extern ogs_tlv_desc_t ogs_tlv_desc_delete_indirect_data_forwarding_tunnel_request;
extern ogs_tlv_desc_t ogs_tlv_desc_delete_indirect_data_forwarding_tunnel_response;
extern ogs_tlv_desc_t ogs_tlv_desc_release_access_bearers_request;
extern ogs_tlv_desc_t ogs_tlv_desc_release_access_bearers_response;
extern ogs_tlv_desc_t ogs_tlv_desc_downlink_data_notification;
extern ogs_tlv_desc_t ogs_tlv_desc_downlink_data_notification_acknowledge;
extern ogs_tlv_desc_t ogs_tlv_desc_pgw_restart_notification;
extern ogs_tlv_desc_t ogs_tlv_desc_pgw_restart_notification_acknowledge;
extern ogs_tlv_desc_t ogs_tlv_desc_update_pdn_connection_set_request;
extern ogs_tlv_desc_t ogs_tlv_desc_update_pdn_connection_set_response;
extern ogs_tlv_desc_t ogs_tlv_desc_modify_access_bearers_request;
extern ogs_tlv_desc_t ogs_tlv_desc_modify_access_bearers_response;

/* Structure for Infomration Element */
typedef ogs_tlv_octet_t ogs_tlv_imsi_t;
typedef ogs_tlv_octet_t ogs_tlv_cause_t;
typedef ogs_tlv_uint8_t ogs_tlv_recovery_t;
typedef ogs_tlv_octet_t ogs_tlv_stn_sr_t;
typedef ogs_tlv_octet_t ogs_tlv_apn_t;
typedef ogs_tlv_octet_t ogs_tlv_ambr_t;
typedef ogs_tlv_uint8_t ogs_tlv_ebi_t;
typedef ogs_tlv_octet_t ogs_tlv_ip_address_t;
typedef ogs_tlv_octet_t ogs_tlv_mei_t;
typedef ogs_tlv_octet_t ogs_tlv_msisdn_t;
typedef ogs_tlv_octet_t ogs_tlv_indication_t;
typedef ogs_tlv_octet_t ogs_tlv_pco_t;
typedef ogs_tlv_octet_t ogs_tlv_paa_t;
typedef ogs_tlv_octet_t ogs_tlv_bearer_qos_t;
typedef ogs_tlv_octet_t ogs_tlv_flow_qos_t;
typedef ogs_tlv_uint8_t ogs_tlv_rat_type_t;
typedef ogs_tlv_octet_t ogs_tlv_serving_network_t;
typedef ogs_tlv_octet_t ogs_tlv_bearer_tft_t;
typedef ogs_tlv_octet_t ogs_tlv_tad_t;
typedef ogs_tlv_octet_t ogs_tlv_uli_t;
typedef ogs_tlv_octet_t ogs_tlv_f_teid_t;
typedef ogs_tlv_octet_t ogs_tlv_tmsi_t;
typedef ogs_tlv_octet_t ogs_tlv_global_cn_id_t;
typedef ogs_tlv_octet_t ogs_tlv_s103pdf_t;
typedef ogs_tlv_octet_t ogs_tlv_s1udf_t;
typedef ogs_tlv_octet_t ogs_tlv_delay_value_t;
typedef ogs_tlv_octet_t ogs_tlv_charging_id_t;
typedef ogs_tlv_octet_t ogs_tlv_charging_characteristics_t;
typedef ogs_tlv_octet_t ogs_tlv_trace_information_t;
typedef ogs_tlv_octet_t ogs_tlv_bearer_flags_t;
typedef ogs_tlv_uint8_t ogs_tlv_pdn_type_t;
typedef ogs_tlv_octet_t ogs_tlv_pti_t;
typedef ogs_tlv_octet_t ogs_tlv_mm_context_t;
typedef ogs_tlv_octet_t ogs_tlv_pdu_numbers_t;
typedef ogs_tlv_octet_t ogs_tlv_p_tmsi_t;
typedef ogs_tlv_octet_t ogs_tlv_p_tmsi_signature_t;
typedef ogs_tlv_octet_t ogs_tlv_hop_counter_t;
typedef ogs_tlv_octet_t ogs_tlv_ue_time_zone_t;
typedef ogs_tlv_octet_t ogs_tlv_trace_reference_t;
typedef ogs_tlv_octet_t ogs_tlv_complete_request_message_t;
typedef ogs_tlv_octet_t ogs_tlv_guti_t;
typedef ogs_tlv_octet_t ogs_tlv_f_container_t;
typedef ogs_tlv_octet_t ogs_tlv_f_cause_t;
typedef ogs_tlv_octet_t ogs_tlv_plmn_id_t;
typedef ogs_tlv_octet_t ogs_tlv_target_identification_t;
typedef ogs_tlv_octet_t ogs_tlv_packet_flow_id_t;
typedef ogs_tlv_octet_t ogs_tlv_rab_context_t;
typedef ogs_tlv_octet_t ogs_tlv_source_rnc_pdcp_context_info_t;
typedef ogs_tlv_uint16_t ogs_tlv_port_number_t;
typedef ogs_tlv_uint8_t ogs_tlv_apn_restriction_t;
typedef ogs_tlv_uint8_t ogs_tlv_selection_mode_t;
typedef ogs_tlv_octet_t ogs_tlv_source_identification_t;
typedef ogs_tlv_octet_t ogs_tlv_change_reporting_action_t;
typedef ogs_tlv_octet_t ogs_tlv_fq_csid_t;
typedef ogs_tlv_octet_t ogs_tlv_channel_needed_t;
typedef ogs_tlv_octet_t ogs_tlv_emlpp_priority_t;
typedef ogs_tlv_uint8_t ogs_tlv_node_type_t;
typedef ogs_tlv_octet_t ogs_tlv_fqdn_t;
typedef ogs_tlv_octet_t ogs_tlv_ti_t;
typedef ogs_tlv_octet_t ogs_tlv_mbms_session_duration_t;
typedef ogs_tlv_octet_t ogs_tlv_mbms_service_area_t;
typedef ogs_tlv_octet_t ogs_tlv_mbms_session_identifier_t;
typedef ogs_tlv_octet_t ogs_tlv_mbms_flow_identifier_t;
typedef ogs_tlv_octet_t ogs_tlv_mbms_ip_multicast_distribution_t;
typedef ogs_tlv_octet_t ogs_tlv_mbms_distribution_acknowledge_t;
typedef ogs_tlv_octet_t ogs_tlv_rfsp_index_t;
typedef ogs_tlv_octet_t ogs_tlv_uci_t;
typedef ogs_tlv_octet_t ogs_tlv_csg_information_reporting_action_t;
typedef ogs_tlv_octet_t ogs_tlv_csg_id_t;
typedef ogs_tlv_octet_t ogs_tlv_cmi_t;
typedef ogs_tlv_octet_t ogs_tlv_service_indicator_t;
typedef ogs_tlv_octet_t ogs_tlv_detach_type_t;
typedef ogs_tlv_octet_t ogs_tlv_ldn_t;
typedef ogs_tlv_octet_t ogs_tlv_node_features_t;
typedef ogs_tlv_octet_t ogs_tlv_mbms_time_to_data_transfer_t;
typedef ogs_tlv_octet_t ogs_tlv_throttling_t;
typedef ogs_tlv_octet_t ogs_tlv_arp_t;
typedef ogs_tlv_octet_t ogs_tlv_epc_timer_t;
typedef ogs_tlv_octet_t ogs_tlv_signalling_priority_indication_t;
typedef ogs_tlv_octet_t ogs_tlv_tmgi_t;
typedef ogs_tlv_octet_t ogs_tlv_additional_mm_context_for_srvcc_t;
typedef ogs_tlv_octet_t ogs_tlv_additional_flags_for_srvcc_t;
typedef ogs_tlv_octet_t ogs_tlv_mdt_configuration_t;
typedef ogs_tlv_octet_t ogs_tlv_apco_t;
typedef ogs_tlv_octet_t ogs_tlv_absolute_time_of_mbms_data_transfer_t;
typedef ogs_tlv_octet_t ogs_tlv_enb_information_reporting_t;
typedef ogs_tlv_octet_t ogs_tlv_ip4cp_t;
typedef ogs_tlv_octet_t ogs_tlv_change_to_report_flags_t;
typedef ogs_tlv_octet_t ogs_tlv_action_indication_t;
typedef ogs_tlv_octet_t ogs_tlv_twan_identifier_t;
typedef ogs_tlv_octet_t ogs_tlv_uli_timestamp_t;
typedef ogs_tlv_octet_t ogs_tlv_mbms_flags_t;
typedef ogs_tlv_octet_t ogs_tlv_ran_nas_cause_t;
typedef ogs_tlv_octet_t ogs_tlv_cn_operator_selection_entity_t;
typedef ogs_tlv_octet_t ogs_tlv_twmi_t;
typedef ogs_tlv_octet_t ogs_tlv_node_number_t;
typedef ogs_tlv_octet_t ogs_tlv_node_identifier_t;
typedef ogs_tlv_octet_t ogs_tlv_presence_reporting_area_action_t;
typedef ogs_tlv_octet_t ogs_tlv_presence_reporting_area_information_t;
typedef ogs_tlv_octet_t ogs_tlv_twan_identifier_timestamp_t;
typedef ogs_tlv_octet_t ogs_tlv_metric_t;
typedef ogs_tlv_octet_t ogs_tlv_sequence_number_t;
typedef ogs_tlv_octet_t ogs_tlv_apn_and_relative_capacity_t;
typedef ogs_tlv_octet_t ogs_tlv_wlan_offloadability_indication_t;
typedef ogs_tlv_octet_t ogs_tlv_paging_and_service_information_t;
typedef ogs_tlv_octet_t ogs_tlv_integer_number_t;
typedef ogs_tlv_octet_t ogs_tlv_millisecond_time_stamp_t;
typedef ogs_tlv_octet_t ogs_tlv_monitoring_event_information_t;
typedef ogs_tlv_octet_t ogs_tlv_ecgi_list_t;
typedef ogs_tlv_octet_t ogs_tlv_remote_user_id_t;
typedef ogs_tlv_octet_t ogs_tlv_remote_ue_ip_information_t;
typedef ogs_tlv_octet_t ogs_tlv_ciot_optimizations_support_indication_t;
typedef ogs_tlv_octet_t ogs_tlv_header_compression_configuration_t;
typedef ogs_tlv_octet_t ogs_tlv_epco_t;
typedef ogs_tlv_octet_t ogs_tlv_serving_plmn_rate_control_t;
typedef ogs_tlv_octet_t ogs_tlv_counter_t;

/* Structure for Group Infomration Element */
typedef struct ogs_tlv_bearer_context_s {
    ogs_tlv_presence_t presence;
    ogs_tlv_ebi_t eps_bearer_id;
    ogs_tlv_bearer_tft_t tft;
    ogs_tlv_f_teid_t s1_u_enodeb_f_teid; /* Instance : 0 */
    ogs_tlv_f_teid_t s4_u_sgsn_f_teid; /* Instance : 1 */
    ogs_tlv_f_teid_t s5_s8_u_sgw_f_teid; /* Instance : 2 */
    ogs_tlv_f_teid_t s5_s8_u_pgw_f_teid; /* Instance : 3 */
    ogs_tlv_f_teid_t s12_rnc_f_teid; /* Instance : 4 */
    ogs_tlv_f_teid_t s2b_u_epdg_f_teid_5; /* Instance : 5 */
    ogs_tlv_f_teid_t s2a_u_twan_f_teid_6; /* Instance : 6 */
    ogs_tlv_bearer_qos_t bearer_level_qos;
    ogs_tlv_f_teid_t s11_u_mme_f_teid; /* Instance : 7 */
    ogs_tlv_cause_t cause;
    ogs_tlv_charging_id_t charging_id;
    ogs_tlv_bearer_flags_t bearer_flags;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_epco_t extended_protocol_configuration_options;
    ogs_tlv_f_teid_t s2b_u_epdg_f_teid_8; /* Instance : 8 */
    ogs_tlv_f_teid_t s2b_u_pgw_f_teid; /* Instance : 9 */
    ogs_tlv_f_teid_t s2a_u_twan_f_teid_10; /* Instance : 10 */
    ogs_tlv_f_teid_t s2a_u_pgw_f_teid; /* Instance : 11 */
    ogs_tlv_ran_nas_cause_t ran_nas_cause;
    ogs_tlv_apco_t additional_protocol_configuration_options;
    ogs_tlv_f_container_t bss_container;
    ogs_tlv_ti_t transaction_identifier;
    ogs_tlv_packet_flow_id_t packet_flow_id;
} ogs_tlv_bearer_context_t;

typedef struct ogs_tlv_pdn_connection_s {
    ogs_tlv_presence_t presence;
} ogs_tlv_pdn_connection_t;

typedef struct ogs_tlv_overload_control_information_s {
    ogs_tlv_presence_t presence;
    ogs_tlv_sequence_number_t overload_control_sequence_number;
    ogs_tlv_metric_t overload_reduction_metric;
    ogs_tlv_epc_timer_t period_of_validity;
    ogs_tlv_apn_t list_of_access_point_name;
} ogs_tlv_overload_control_information_t;

typedef struct ogs_tlv_load_control_information_s {
    ogs_tlv_presence_t presence;
    ogs_tlv_sequence_number_t load_control_sequence_number;
    ogs_tlv_metric_t load_metric;
    ogs_tlv_apn_and_relative_capacity_t list_of_apn_and_relative_capacity;
} ogs_tlv_load_control_information_t;

typedef struct ogs_tlv_remote_ue_context_s {
    ogs_tlv_presence_t presence;
    ogs_tlv_remote_user_id_t remote_user_id;
    ogs_tlv_remote_ue_ip_information_t remote_ue_ip_information;
} ogs_tlv_remote_ue_context_t;

typedef struct ogs_tlv_scef_pdn_connection_s {
    ogs_tlv_presence_t presence;
    ogs_tlv_apn_t apn;
    ogs_tlv_ebi_t default_eps_bearer_id;
    ogs_tlv_node_identifier_t scef_id;
} ogs_tlv_scef_pdn_connection_t;

/* Structure for Message */
typedef struct ogs_gtp_echo_request_s {
    ogs_tlv_recovery_t recovery;
    ogs_tlv_node_features_t sending_node_features;
} ogs_gtp_echo_request_t;

typedef struct ogs_gtp_echo_response_s {
    ogs_tlv_recovery_t recovery;
    ogs_tlv_node_features_t sending_node_features;
} ogs_gtp_echo_response_t;

typedef struct ogs_gtp_create_session_request_s {
    ogs_tlv_imsi_t imsi;
    ogs_tlv_msisdn_t msisdn;
    ogs_tlv_mei_t me_identity;
    ogs_tlv_uli_t user_location_information;
    ogs_tlv_serving_network_t serving_network;
    ogs_tlv_rat_type_t rat_type;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_f_teid_t sender_f_teid_for_control_plane;
    ogs_tlv_f_teid_t pgw_s5_s8_address_for_control_plane_or_pmip;
    ogs_tlv_apn_t access_point_name;
    ogs_tlv_selection_mode_t selection_mode;
    ogs_tlv_pdn_type_t pdn_type;
    ogs_tlv_paa_t pdn_address_allocation;
    ogs_tlv_apn_restriction_t maximum_apn_restriction;
    ogs_tlv_ambr_t aggregate_maximum_bit_rate;
    ogs_tlv_ebi_t linked_eps_bearer_id;
    ogs_tlv_twmi_t trusted_wlan_mode_indication;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_bearer_context_t bearer_contexts_to_be_created;
    ogs_tlv_bearer_context_t bearer_contexts_to_be_removed;
    ogs_tlv_trace_information_t trace_information;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_fq_csid_t mme_fq_csid;
    ogs_tlv_fq_csid_t sgw_fq_csid;
    ogs_tlv_fq_csid_t epdg_fq_csid;
    ogs_tlv_fq_csid_t twan_fq_csid;
    ogs_tlv_ue_time_zone_t ue_time_zone;
    ogs_tlv_uci_t user_csg_information;
    ogs_tlv_charging_characteristics_t charging_characteristics;
    ogs_tlv_ldn_t mme_s4_sgsn_ldn;
    ogs_tlv_ldn_t sgw_ldn;
    ogs_tlv_ldn_t epdg_ldn;
    ogs_tlv_ldn_t twan_ldn;
    ogs_tlv_signalling_priority_indication_t signalling_priority_indication;
    ogs_tlv_ip_address_t ue_local_ip_address;
    ogs_tlv_port_number_t ue_udp_port;
    ogs_tlv_apco_t additional_protocol_configuration_options;
    ogs_tlv_ip_address_t hnb_local_ip_address;
    ogs_tlv_port_number_t hnb_udp_port;
    ogs_tlv_ip_address_t mme_s4_sgsn_identifier;
    ogs_tlv_twan_identifier_t twan_identifier;
    ogs_tlv_ip_address_t epdg_ip_address;
    ogs_tlv_cn_operator_selection_entity_t cn_operator_selection_entity;
    ogs_tlv_presence_reporting_area_information_t presence_reporting_area_information;
    ogs_tlv_overload_control_information_t mme_s4_sgsn_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t twan_epdg_s_overload_control_information;
    ogs_tlv_millisecond_time_stamp_t origination_time_stamp;
    ogs_tlv_integer_number_t maximum_wait_time;
    ogs_tlv_twan_identifier_t wlan_location_information;
    ogs_tlv_twan_identifier_timestamp_t wlan_location_timestamp;
    ogs_tlv_f_container_t nbifom_container;
    ogs_tlv_remote_ue_context_t remote_ue_context_connected;
    ogs_tlv_node_identifier_t _aaa_server_identifier;
    ogs_tlv_epco_t extended_protocol_configuration_options;
    ogs_tlv_serving_plmn_rate_control_t serving_plmn_rate_control;
    ogs_tlv_counter_t mo_exception_data_counter;
    ogs_tlv_port_number_t ue_tcp_port;
} ogs_gtp_create_session_request_t;

typedef struct ogs_gtp_create_session_response_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_change_reporting_action_t change_reporting_action_;
    ogs_tlv_csg_information_reporting_action_t csg_information_reporting_action;
    ogs_tlv_enb_information_reporting_t hnb_information_reporting;
    ogs_tlv_f_teid_t sender_f_teid_for_control_plane;
    ogs_tlv_f_teid_t pgw_s5_s8__s2a_s2b_f_teid_for_pmip_based_interface_or_for_gtp_based_control_plane_interface;
    ogs_tlv_paa_t pdn_address_allocation;
    ogs_tlv_apn_restriction_t apn_restriction;
    ogs_tlv_ambr_t aggregate_maximum_bit_rate;
    ogs_tlv_ebi_t linked_eps_bearer_id;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_bearer_context_t bearer_contexts_created;
    ogs_tlv_bearer_context_t bearer_contexts_marked_for_removal;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_fqdn_t charging_gateway_name;
    ogs_tlv_ip_address_t charging_gateway_address;
    ogs_tlv_fq_csid_t pgw_fq_csid;
    ogs_tlv_fq_csid_t sgw_fq_csid;
    ogs_tlv_ldn_t sgw_ldn;
    ogs_tlv_ldn_t pgw_ldn;
    ogs_tlv_epc_timer_t pgw_back_off_time;
    ogs_tlv_apco_t additional_protocol_configuration_options;
    ogs_tlv_ip4cp_t trusted_wlan_ipv4_parameters_;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_presence_reporting_area_action_t presence_reporting_area_action;
    ogs_tlv_load_control_information_t pgw_s_node_level_load_control_information;
    ogs_tlv_load_control_information_t pgw_s_apn_level_load_control_information;
    ogs_tlv_load_control_information_t sgw_s_node_level_load_control_information;
    ogs_tlv_overload_control_information_t pgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_f_container_t nbifom_container;
    ogs_tlv_charging_id_t pdn_connection_charging_id;
    ogs_tlv_epco_t extended_protocol_configuration_options;
} ogs_gtp_create_session_response_t;

typedef struct ogs_gtp_modify_bearer_request_s {
    ogs_tlv_mei_t me_identity;
    ogs_tlv_uli_t user_location_information;
    ogs_tlv_serving_network_t serving_network;
    ogs_tlv_rat_type_t rat_type;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_f_teid_t sender_f_teid_for_control_plane;
    ogs_tlv_ambr_t aggregate_maximum_bit_rate;
    ogs_tlv_delay_value_t delay_downlink_packet_notification_request;
    ogs_tlv_bearer_context_t bearer_contexts_to_be_modified;
    ogs_tlv_bearer_context_t bearer_contexts_to_be_removed;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_ue_time_zone_t ue_time_zone;
    ogs_tlv_fq_csid_t mme_fq_csid;
    ogs_tlv_uci_t user_csg_information;
    ogs_tlv_ip_address_t ue_local_ip_address;
    ogs_tlv_port_number_t ue_udp_port;
    ogs_tlv_ldn_t mme_s4_sgsn_ldn;
    ogs_tlv_ldn_t sgw_ldn;
    ogs_tlv_ip_address_t hnb_local_ip_address;
    ogs_tlv_port_number_t hnb_udp_port;
    ogs_tlv_ip_address_t mme_s4_sgsn_identifier;
    ogs_tlv_cn_operator_selection_entity_t cn_operator_selection_entity;
    ogs_tlv_presence_reporting_area_information_t presence_reporting_area_information;
    ogs_tlv_overload_control_information_t mme_s4_sgsn_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t epdg_s_overload_control_information;
    ogs_tlv_serving_plmn_rate_control_t serving_plmn_rate_control;
    ogs_tlv_counter_t mo_exception_data_counter;
} ogs_gtp_modify_bearer_request_t;

typedef struct ogs_gtp_modify_bearer_response_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_msisdn_t msisdn;
    ogs_tlv_ebi_t linked_eps_bearer_id;
    ogs_tlv_apn_restriction_t apn_restriction;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_bearer_context_t bearer_contexts_modified;
    ogs_tlv_bearer_context_t bearer_contexts_marked_for_removal;
    ogs_tlv_change_reporting_action_t change_reporting_action;
    ogs_tlv_csg_information_reporting_action_t csg_information_reporting_action;
    ogs_tlv_enb_information_reporting_t hnb_information_reporting_;
    ogs_tlv_fqdn_t charging_gateway_name;
    ogs_tlv_ip_address_t charging_gateway_address;
    ogs_tlv_fq_csid_t pgw_fq_csid;
    ogs_tlv_fq_csid_t sgw_fq_csid;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_ldn_t sgw_ldn;
    ogs_tlv_ldn_t pgw_ldn;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_presence_reporting_area_action_t presence_reporting_area_action;
    ogs_tlv_load_control_information_t pgw_s_node_level_load_control_information;
    ogs_tlv_load_control_information_t pgw_s_apn_level_load_control_information;
    ogs_tlv_load_control_information_t sgw_s_node_level_load_control_information;
    ogs_tlv_overload_control_information_t pgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_charging_id_t pdn_connection_charging_id;
} ogs_gtp_modify_bearer_response_t;

typedef struct ogs_gtp_delete_session_request_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_ebi_t linked_eps_bearer_id;
    ogs_tlv_uli_t user_location_information;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_node_type_t originating_node;
    ogs_tlv_f_teid_t sender_f_teid_for_control_plane;
    ogs_tlv_ue_time_zone_t ue_time_zone;
    ogs_tlv_uli_timestamp_t uli_timestamp;
    ogs_tlv_ran_nas_cause_t ran_nas_release_cause;
    ogs_tlv_twan_identifier_t twan_identifier;
    ogs_tlv_twan_identifier_timestamp_t twan_identifier_timestamp;
    ogs_tlv_overload_control_information_t mme_s4_sgsn_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t twan_epdg_s_overload_control_information;
    ogs_tlv_twan_identifier_t wlan_location_information;
    ogs_tlv_twan_identifier_timestamp_t wlan_location_timestamp;
    ogs_tlv_ip_address_t ue_local_ip_address;
    ogs_tlv_port_number_t ue_udp_port;
    ogs_tlv_epco_t extended_protocol_configuration_options;
    ogs_tlv_port_number_t ue_tcp_port;
} ogs_gtp_delete_session_request_t;

typedef struct ogs_gtp_delete_session_response_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_load_control_information_t pgw_s_node_level_load_control_information;
    ogs_tlv_load_control_information_t pgw_s_apn_level_load_control_information;
    ogs_tlv_load_control_information_t sgw_s_node_level_load_control_information;
    ogs_tlv_overload_control_information_t pgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_epco_t extended_protocol_configuration_options;
} ogs_gtp_delete_session_response_t;

typedef struct ogs_gtp_modify_bearer_command_s {
    ogs_tlv_ambr_t apn_aggregate_maximum_bit_rate;
    ogs_tlv_bearer_context_t bearer_context;
    ogs_tlv_overload_control_information_t mme_s4_sgsn_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t twan_epdg_s_overload_control_information;
    ogs_tlv_f_teid_t sender_f_teid_for_control_plane;
} ogs_gtp_modify_bearer_command_t;

typedef struct ogs_gtp_modify_bearer_failure_indication_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_overload_control_information_t pgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
} ogs_gtp_modify_bearer_failure_indication_t;

typedef struct ogs_gtp_delete_bearer_command_s {
    ogs_tlv_bearer_context_t bearer_contexts;
    ogs_tlv_uli_t user_location_information;
    ogs_tlv_uli_timestamp_t uli_timestamp;
    ogs_tlv_ue_time_zone_t ue_time_zone;
    ogs_tlv_overload_control_information_t mme_s4_sgsn_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_f_teid_t sender_f_teid_for_control_plane;
} ogs_gtp_delete_bearer_command_t;

typedef struct ogs_gtp_delete_bearer_failure_indication_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_bearer_context_t bearer_context;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_overload_control_information_t pgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
} ogs_gtp_delete_bearer_failure_indication_t;

typedef struct ogs_gtp_downlink_data_notification_failure_indication_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_node_type_t originating_node;
    ogs_tlv_imsi_t imsi;
} ogs_gtp_downlink_data_notification_failure_indication_t;

typedef struct ogs_gtp_create_bearer_request_s {
    ogs_tlv_pti_t procedure_transaction_id;
    ogs_tlv_ebi_t linked_eps_bearer_id;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_bearer_context_t bearer_contexts;
    ogs_tlv_fq_csid_t pgw_fq_csid;
    ogs_tlv_fq_csid_t sgw_fq_csid;
    ogs_tlv_change_reporting_action_t change_reporting_action;
    ogs_tlv_csg_information_reporting_action_t csg_information_reporting_action;
    ogs_tlv_enb_information_reporting_t hnb_information_reporting;
    ogs_tlv_presence_reporting_area_action_t presence_reporting_area_action;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_load_control_information_t pgw_s_node_level_load_control_information;
    ogs_tlv_load_control_information_t pgw_s_apn_level_load_control_information;
    ogs_tlv_load_control_information_t sgw_s_node_level_load_control_information;
    ogs_tlv_overload_control_information_t pgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_f_container_t nbifom_container;
} ogs_gtp_create_bearer_request_t;

typedef struct ogs_gtp_create_bearer_response_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_bearer_context_t bearer_contexts;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_fq_csid_t mme_fq_csid;
    ogs_tlv_fq_csid_t epdg_fq_csid;
    ogs_tlv_fq_csid_t twan_fq_csid;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_ue_time_zone_t ue_time_zone;
    ogs_tlv_uli_t user_location_information;
    ogs_tlv_twan_identifier_t twan_identifier;
    ogs_tlv_overload_control_information_t mme_s4_sgsn_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_presence_reporting_area_information_t presence_reporting_area_information;
    ogs_tlv_ip_address_t mme_s4_sgsn_identifier;
    ogs_tlv_overload_control_information_t twan_epdg_s_overload_control_information;
    ogs_tlv_twan_identifier_t wlan_location_information;
    ogs_tlv_twan_identifier_timestamp_t wlan_location_timestamp;
    ogs_tlv_port_number_t ue_udp_port;
    ogs_tlv_f_container_t nbifom_container;
    ogs_tlv_port_number_t ue_tcp_port;
} ogs_gtp_create_bearer_response_t;

typedef struct ogs_gtp_update_bearer_request_s {
    ogs_tlv_bearer_context_t bearer_contexts;
    ogs_tlv_pti_t procedure_transaction_id;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_ambr_t aggregate_maximum_bit_rate;
    ogs_tlv_change_reporting_action_t change_reporting_action;
    ogs_tlv_csg_information_reporting_action_t csg_information_reporting_action;
    ogs_tlv_enb_information_reporting_t hnb_information_reporting_;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_fq_csid_t pgw_fq_csid;
    ogs_tlv_fq_csid_t sgw_fq_csid;
    ogs_tlv_presence_reporting_area_action_t presence_reporting_area_action;
    ogs_tlv_load_control_information_t pgw_s_node_level_load_control_information;
    ogs_tlv_load_control_information_t pgw_s_apn_level_load_control_information;
    ogs_tlv_load_control_information_t sgw_s_node_level_load_control_information;
    ogs_tlv_overload_control_information_t pgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_f_container_t nbifom_container;
} ogs_gtp_update_bearer_request_t;

typedef struct ogs_gtp_update_bearer_response_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_bearer_context_t bearer_contexts;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_fq_csid_t mme_fq_csid;
    ogs_tlv_fq_csid_t sgw_fq_csid;
    ogs_tlv_fq_csid_t epdg_fq_csid;
    ogs_tlv_fq_csid_t twan_fq_csid;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_ue_time_zone_t ue_time_zone;
    ogs_tlv_uli_t user_location_information;
    ogs_tlv_twan_identifier_t twan_identifier;
    ogs_tlv_overload_control_information_t mme_s4_sgsn_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_presence_reporting_area_information_t presence_reporting_area_information;
    ogs_tlv_ip_address_t mme_s4_sgsn_identifier;
    ogs_tlv_overload_control_information_t twan_epdg_s_overload_control_information;
    ogs_tlv_twan_identifier_t wlan_location_information;
    ogs_tlv_twan_identifier_timestamp_t wlan_location_timestamp;
    ogs_tlv_port_number_t ue_udp_port;
    ogs_tlv_f_container_t nbifom_container;
    ogs_tlv_port_number_t ue_tcp_port;
} ogs_gtp_update_bearer_response_t;

typedef struct ogs_gtp_delete_bearer_request_s {
    ogs_tlv_ebi_t linked_eps_bearer_id;
    ogs_tlv_ebi_t eps_bearer_ids;
    ogs_tlv_bearer_context_t failed_bearer_contexts;
    ogs_tlv_pti_t procedure_transaction_id;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_fq_csid_t pgw_fq_csid;
    ogs_tlv_fq_csid_t sgw_fq_csid;
    ogs_tlv_cause_t cause;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_load_control_information_t pgw_s_node_level_load_control_information;
    ogs_tlv_load_control_information_t pgw_s_apn_level_load_control_information;
    ogs_tlv_load_control_information_t sgw_s_node_level_load_control_information;
    ogs_tlv_overload_control_information_t pgw_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_f_container_t nbifom_container;
    ogs_tlv_epco_t extended_protocol_configuration_options;
} ogs_gtp_delete_bearer_request_t;

typedef struct ogs_gtp_delete_bearer_response_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_ebi_t linked_eps_bearer_id;
    ogs_tlv_bearer_context_t bearer_contexts;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_fq_csid_t mme_fq_csid;
    ogs_tlv_fq_csid_t sgw_fq_csid;
    ogs_tlv_fq_csid_t epdg_fq_csid;
    ogs_tlv_fq_csid_t twan_fq_csid;
    ogs_tlv_pco_t protocol_configuration_options;
    ogs_tlv_ue_time_zone_t ue_time_zone;
    ogs_tlv_uli_t user_location_information;
    ogs_tlv_uli_timestamp_t uli_timestamp;
    ogs_tlv_twan_identifier_t twan_identifier;
    ogs_tlv_twan_identifier_timestamp_t twan_identifier_timestamp;
    ogs_tlv_overload_control_information_t mme_s4_sgsn_s_overload_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_ip_address_t mme_s4_sgsn_identifier;
    ogs_tlv_overload_control_information_t twan_epdg_s_overload_control_information;
    ogs_tlv_twan_identifier_t wlan_location_information;
    ogs_tlv_twan_identifier_timestamp_t wlan_location_timestamp;
    ogs_tlv_port_number_t ue_udp_port;
    ogs_tlv_f_container_t nbifom_container;
    ogs_tlv_port_number_t ue_tcp_port	;
} ogs_gtp_delete_bearer_response_t;

typedef struct ogs_gtp_create_indirect_data_forwarding_tunnel_request_s {
    ogs_tlv_imsi_t imsi;
    ogs_tlv_mei_t me_identity;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_f_teid_t sender_f_teid_for_control_plane;
    ogs_tlv_bearer_context_t bearer_context_0;
    ogs_tlv_bearer_context_t bearer_context_1;
    ogs_tlv_bearer_context_t bearer_context_2;
    ogs_tlv_bearer_context_t bearer_context_3;
    ogs_tlv_bearer_context_t bearer_context_4;
    ogs_tlv_bearer_context_t bearer_context_5;
    ogs_tlv_bearer_context_t bearer_context_6;
    ogs_tlv_bearer_context_t bearer_context_7;
    ogs_tlv_bearer_context_t bearer_context_8;
    ogs_tlv_bearer_context_t bearer_context_9;
    ogs_tlv_bearer_context_t bearer_context_10;
    ogs_tlv_recovery_t recovery;
} ogs_gtp_create_indirect_data_forwarding_tunnel_request_t;

typedef struct ogs_gtp_create_indirect_data_forwarding_tunnel_response_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_f_teid_t sender_f_teid_for_control_plane;
    ogs_tlv_bearer_context_t bearer_context_0;
    ogs_tlv_bearer_context_t bearer_context_1;
    ogs_tlv_bearer_context_t bearer_context_2;
    ogs_tlv_bearer_context_t bearer_context_3;
    ogs_tlv_bearer_context_t bearer_context_4;
    ogs_tlv_bearer_context_t bearer_context_5;
    ogs_tlv_bearer_context_t bearer_context_6;
    ogs_tlv_bearer_context_t bearer_context_7;
    ogs_tlv_bearer_context_t bearer_context_8;
    ogs_tlv_bearer_context_t bearer_context_9;
    ogs_tlv_bearer_context_t bearer_context_10;
    ogs_tlv_recovery_t recovery;
} ogs_gtp_create_indirect_data_forwarding_tunnel_response_t;

typedef struct ogs_gtp_delete_indirect_data_forwarding_tunnel_request_s {
} ogs_gtp_delete_indirect_data_forwarding_tunnel_request_t;

typedef struct ogs_gtp_delete_indirect_data_forwarding_tunnel_response_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_recovery_t recovery;
} ogs_gtp_delete_indirect_data_forwarding_tunnel_response_t;

typedef struct ogs_gtp_release_access_bearers_request_s {
    ogs_tlv_ebi_t list_of_rabs;
    ogs_tlv_node_type_t originating_node;
    ogs_tlv_indication_t indication_flags;
} ogs_gtp_release_access_bearers_request_t;

typedef struct ogs_gtp_release_access_bearers_response_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_load_control_information_t sgw_s_node_level_load_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
} ogs_gtp_release_access_bearers_response_t;

typedef struct ogs_gtp_downlink_data_notification_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_ebi_t eps_bearer_id;
    ogs_tlv_arp_t allocation_retention_priority;
    ogs_tlv_imsi_t imsi;
    ogs_tlv_f_teid_t sender_f_teid_for_control_plane;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_load_control_information_t sgw_s_node_level_load_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
    ogs_tlv_paging_and_service_information_t paging_and_service_information;
} ogs_gtp_downlink_data_notification_t;

typedef struct ogs_gtp_downlink_data_notification_acknowledge_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_delay_value_t data_notification_delay;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_throttling_t dl_low_priority_traffic_throttling_;
    ogs_tlv_imsi_t imsi;
    ogs_tlv_epc_timer_t dl_buffering_duration;
    ogs_tlv_integer_number_t dl_buffering_suggested_packet_count;
} ogs_gtp_downlink_data_notification_acknowledge_t;

typedef struct ogs_gtp_modify_access_bearers_request_s {
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_f_teid_t sender_f_teid_for_control_plane;
    ogs_tlv_delay_value_t delay_downlink_packet_notification_request;
    ogs_tlv_bearer_context_t bearer_contexts_to_be_modified;
    ogs_tlv_bearer_context_t bearer_contexts_to_be_removed;
    ogs_tlv_recovery_t recovery;
} ogs_gtp_modify_access_bearers_request_t;

typedef struct ogs_gtp_modify_access_bearers_response_s {
    ogs_tlv_cause_t cause;
    ogs_tlv_bearer_context_t bearer_contexts_modified;
    ogs_tlv_bearer_context_t bearer_contexts_marked_for_removal;
    ogs_tlv_recovery_t recovery;
    ogs_tlv_indication_t indication_flags;
    ogs_tlv_load_control_information_t sgw_s_node_level_load_control_information;
    ogs_tlv_overload_control_information_t sgw_s_overload_control_information;
} ogs_gtp_modify_access_bearers_response_t;

typedef struct ogs_gtp_message_s {
   ogs_gtp_header_t h;
   union {
        ogs_gtp_echo_request_t echo_request;
        ogs_gtp_echo_response_t echo_response;
        ogs_gtp_create_session_request_t create_session_request;
        ogs_gtp_create_session_response_t create_session_response;
        ogs_gtp_modify_bearer_request_t modify_bearer_request;
        ogs_gtp_modify_bearer_response_t modify_bearer_response;
        ogs_gtp_delete_session_request_t delete_session_request;
        ogs_gtp_delete_session_response_t delete_session_response;
        ogs_gtp_modify_bearer_command_t modify_bearer_command;
        ogs_gtp_modify_bearer_failure_indication_t modify_bearer_failure_indication;
        ogs_gtp_delete_bearer_command_t delete_bearer_command;
        ogs_gtp_delete_bearer_failure_indication_t delete_bearer_failure_indication;
        ogs_gtp_downlink_data_notification_failure_indication_t downlink_data_notification_failure_indication;
        ogs_gtp_create_bearer_request_t create_bearer_request;
        ogs_gtp_create_bearer_response_t create_bearer_response;
        ogs_gtp_update_bearer_request_t update_bearer_request;
        ogs_gtp_update_bearer_response_t update_bearer_response;
        ogs_gtp_delete_bearer_request_t delete_bearer_request;
        ogs_gtp_delete_bearer_response_t delete_bearer_response;
        ogs_gtp_create_indirect_data_forwarding_tunnel_request_t create_indirect_data_forwarding_tunnel_request;
        ogs_gtp_create_indirect_data_forwarding_tunnel_response_t create_indirect_data_forwarding_tunnel_response;
        ogs_gtp_delete_indirect_data_forwarding_tunnel_request_t delete_indirect_data_forwarding_tunnel_request;
        ogs_gtp_delete_indirect_data_forwarding_tunnel_response_t delete_indirect_data_forwarding_tunnel_response;
        ogs_gtp_release_access_bearers_request_t release_access_bearers_request;
        ogs_gtp_release_access_bearers_response_t release_access_bearers_response;
        ogs_gtp_downlink_data_notification_t downlink_data_notification;
        ogs_gtp_downlink_data_notification_acknowledge_t downlink_data_notification_acknowledge;
        ogs_gtp_modify_access_bearers_request_t modify_access_bearers_request;
        ogs_gtp_modify_access_bearers_response_t modify_access_bearers_response;
   };
} ogs_gtp_message_t;

int ogs_gtp_parse_msg(ogs_gtp_message_t *gtp_message, ogs_pkbuf_t *pkbuf);
int ogs_gtp_build_msg(ogs_pkbuf_t **pkbuf, ogs_gtp_message_t *gtp_message);

#ifdef __cplusplus
}
#endif

#endif /* OGS_GTP_MESSAGE_H */
