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

#ifndef OGS_S1AP_H
#define OGS_S1AP_H

#include "ogs-common.h"

#include "S1AP_Additional-GUTI.h"
#include "S1AP_AdditionalCSFallbackIndicator.h"
#include "S1AP_AllocationAndRetentionPriority.h"
#include "S1AP_AreaScopeOfMDT.h"
#include "S1AP_AssistanceDataForCECapableUEs.h"
#include "S1AP_AssistanceDataForPaging.h"
#include "S1AP_AssistanceDataForRecommendedCells.h"
#include "S1AP_BPLMNs.h"
#include "S1AP_BearerType.h"
#include "S1AP_Bearers-SubjectToStatusTransfer-Item.h"
#include "S1AP_Bearers-SubjectToStatusTransferList.h"
#include "S1AP_BitRate.h"
#include "S1AP_BroadcastCancelledAreaList.h"
#include "S1AP_BroadcastCompletedAreaList.h"
#include "S1AP_CE-mode-B-SupportIndicator.h"
#include "S1AP_CELevel.h"
#include "S1AP_CGI.h"
#include "S1AP_CI.h"
#include "S1AP_CNDomain.h"
#include "S1AP_COUNTValueExtended.h"
#include "S1AP_COUNTvalue.h"
#include "S1AP_COUNTvaluePDCP-SNlength18.h"
#include "S1AP_CSFallbackIndicator.h"
#include "S1AP_CSG-Id.h"
#include "S1AP_CSG-IdList-Item.h"
#include "S1AP_CSG-IdList.h"
#include "S1AP_CSGMembershipInfo.h"
#include "S1AP_CSGMembershipStatus.h"
#include "S1AP_CancelledCellinEAI-Item.h"
#include "S1AP_CancelledCellinEAI.h"
#include "S1AP_CancelledCellinTAI-Item.h"
#include "S1AP_CancelledCellinTAI.h"
#include "S1AP_Cause.h"
#include "S1AP_CauseMisc.h"
#include "S1AP_CauseNas.h"
#include "S1AP_CauseProtocol.h"
#include "S1AP_CauseRadioNetwork.h"
#include "S1AP_CauseTransport.h"
#include "S1AP_Cdma2000HORequiredIndication.h"
#include "S1AP_Cdma2000HOStatus.h"
#include "S1AP_Cdma2000OneXMEID.h"
#include "S1AP_Cdma2000OneXMSI.h"
#include "S1AP_Cdma2000OneXPilot.h"
#include "S1AP_Cdma2000OneXRAND.h"
#include "S1AP_Cdma2000OneXSRVCCInfo.h"
#include "S1AP_Cdma2000PDU.h"
#include "S1AP_Cdma2000RATType.h"
#include "S1AP_Cdma2000SectorID.h"
#include "S1AP_Cell-Size.h"
#include "S1AP_CellAccessMode.h"
#include "S1AP_CellBasedMDT.h"
#include "S1AP_CellID-Broadcast-Item.h"
#include "S1AP_CellID-Broadcast.h"
#include "S1AP_CellID-Cancelled-Item.h"
#include "S1AP_CellID-Cancelled.h"
#include "S1AP_CellIdListforMDT.h"
#include "S1AP_CellIdentifierAndCELevelForCECapableUEs.h"
#include "S1AP_CellIdentity.h"
#include "S1AP_CellTrafficTrace.h"
#include "S1AP_CellType.h"
#include "S1AP_CompletedCellinEAI-Item.h"
#include "S1AP_CompletedCellinEAI.h"
#include "S1AP_CompletedCellinTAI-Item.h"
#include "S1AP_CompletedCellinTAI.h"
#include "S1AP_ConcurrentWarningMessageIndicator.h"
#include "S1AP_ConnectionEstablishmentIndication.h"
#include "S1AP_Correlation-ID.h"
#include "S1AP_Coverage-Level.h"
#include "S1AP_Criticality.h"
#include "S1AP_CriticalityDiagnostics-IE-Item.h"
#include "S1AP_CriticalityDiagnostics-IE-List.h"
#include "S1AP_CriticalityDiagnostics.h"
#include "S1AP_DCN-ID.h"
#include "S1AP_DL-CP-SecurityInformation.h"
#include "S1AP_DL-Forwarding.h"
#include "S1AP_DL-NAS-MAC.h"
#include "S1AP_DLNASPDUDeliveryAckRequest.h"
#include "S1AP_Data-Forwarding-Not-Possible.h"
#include "S1AP_DataCodingScheme.h"
#include "S1AP_DeactivateTrace.h"
#include "S1AP_Direct-Forwarding-Path-Availability.h"
#include "S1AP_DownlinkNASTransport.h"
#include "S1AP_DownlinkNonUEAssociatedLPPaTransport.h"
#include "S1AP_DownlinkS1cdma2000tunnelling.h"
#include "S1AP_DownlinkUEAssociatedLPPaTransport.h"
#include "S1AP_E-RAB-ID.h"
#include "S1AP_E-RAB-IE-ContainerList.h"
#include "S1AP_E-RAB-IE-ContainerPairList.h"
#include "S1AP_E-RABAdmittedItem.h"
#include "S1AP_E-RABAdmittedList.h"
#include "S1AP_E-RABDataForwardingItem.h"
#include "S1AP_E-RABFailedToResumeItemResumeReq.h"
#include "S1AP_E-RABFailedToResumeItemResumeRes.h"
#include "S1AP_E-RABFailedToResumeListResumeReq.h"
#include "S1AP_E-RABFailedToResumeListResumeRes.h"
#include "S1AP_E-RABFailedToSetupItemHOReqAck.h"
#include "S1AP_E-RABFailedtoSetupListHOReqAck.h"
#include "S1AP_E-RABInformationList.h"
#include "S1AP_E-RABInformationListItem.h"
#include "S1AP_E-RABItem.h"
#include "S1AP_E-RABLevelQoSParameters.h"
#include "S1AP_E-RABList.h"
#include "S1AP_E-RABModificationConfirm.h"
#include "S1AP_E-RABModificationIndication.h"
#include "S1AP_E-RABModifyItemBearerModConf.h"
#include "S1AP_E-RABModifyItemBearerModRes.h"
#include "S1AP_E-RABModifyListBearerModConf.h"
#include "S1AP_E-RABModifyListBearerModRes.h"
#include "S1AP_E-RABModifyRequest.h"
#include "S1AP_E-RABModifyResponse.h"
#include "S1AP_E-RABNotToBeModifiedItemBearerModInd.h"
#include "S1AP_E-RABNotToBeModifiedListBearerModInd.h"
#include "S1AP_E-RABReleaseCommand.h"
#include "S1AP_E-RABReleaseIndication.h"
#include "S1AP_E-RABReleaseItemBearerRelComp.h"
#include "S1AP_E-RABReleaseListBearerRelComp.h"
#include "S1AP_E-RABReleaseResponse.h"
#include "S1AP_E-RABSetupItemBearerSURes.h"
#include "S1AP_E-RABSetupItemCtxtSURes.h"
#include "S1AP_E-RABSetupListBearerSURes.h"
#include "S1AP_E-RABSetupListCtxtSURes.h"
#include "S1AP_E-RABSetupRequest.h"
#include "S1AP_E-RABSetupResponse.h"
#include "S1AP_E-RABSubjecttoDataForwardingList.h"
#include "S1AP_E-RABToBeModifiedItemBearerModInd.h"
#include "S1AP_E-RABToBeModifiedItemBearerModReq.h"
#include "S1AP_E-RABToBeModifiedListBearerModInd.h"
#include "S1AP_E-RABToBeModifiedListBearerModReq.h"
#include "S1AP_E-RABToBeSetupItemBearerSUReq.h"
#include "S1AP_E-RABToBeSetupItemCtxtSUReq.h"
#include "S1AP_E-RABToBeSetupItemHOReq.h"
#include "S1AP_E-RABToBeSetupListBearerSUReq.h"
#include "S1AP_E-RABToBeSetupListCtxtSUReq.h"
#include "S1AP_E-RABToBeSetupListHOReq.h"
#include "S1AP_E-RABToBeSwitchedDLItem.h"
#include "S1AP_E-RABToBeSwitchedDLList.h"
#include "S1AP_E-RABToBeSwitchedULItem.h"
#include "S1AP_E-RABToBeSwitchedULList.h"
#include "S1AP_E-UTRAN-Trace-ID.h"
#include "S1AP_EARFCN.h"
#include "S1AP_ECGI-List.h"
#include "S1AP_ECGIList.h"
#include "S1AP_ECGIListForRestart.h"
#include "S1AP_ENB-ID.h"
#include "S1AP_ENB-StatusTransfer-TransparentContainer.h"
#include "S1AP_ENB-UE-S1AP-ID.h"
#include "S1AP_ENBCPRelocationIndication.h"
#include "S1AP_ENBConfigurationTransfer.h"
#include "S1AP_ENBConfigurationUpdate.h"
#include "S1AP_ENBConfigurationUpdateAcknowledge.h"
#include "S1AP_ENBConfigurationUpdateFailure.h"
#include "S1AP_ENBDirectInformationTransfer.h"
#include "S1AP_ENBIndirectX2TransportLayerAddresses.h"
#include "S1AP_ENBStatusTransfer.h"
#include "S1AP_ENBX2ExtTLA.h"
#include "S1AP_ENBX2ExtTLAs.h"
#include "S1AP_ENBX2GTPTLAs.h"
#include "S1AP_ENBX2TLAs.h"
#include "S1AP_ENBname.h"
#include "S1AP_EPLMNs.h"
#include "S1AP_EUTRAN-CGI.h"
#include "S1AP_EUTRANRoundTripDelayEstimationInfo.h"
#include "S1AP_EmergencyAreaID-Broadcast-Item.h"
#include "S1AP_EmergencyAreaID-Broadcast.h"
#include "S1AP_EmergencyAreaID-Cancelled-Item.h"
#include "S1AP_EmergencyAreaID-Cancelled.h"
#include "S1AP_EmergencyAreaID.h"
#include "S1AP_EmergencyAreaIDList.h"
#include "S1AP_EmergencyAreaIDListForRestart.h"
#include "S1AP_EncryptionAlgorithms.h"
#include "S1AP_EnhancedCoverageRestricted.h"
#include "S1AP_ErrorIndication.h"
#include "S1AP_EventType.h"
#include "S1AP_ExpectedActivityPeriod.h"
#include "S1AP_ExpectedHOInterval.h"
#include "S1AP_ExpectedIdlePeriod.h"
#include "S1AP_ExpectedUEActivityBehaviour.h"
#include "S1AP_ExpectedUEBehaviour.h"
#include "S1AP_Extended-UEIdentityIndexValue.h"
#include "S1AP_ExtendedRNC-ID.h"
#include "S1AP_ExtendedRepetitionPeriod.h"
#include "S1AP_ForbiddenInterRATs.h"
#include "S1AP_ForbiddenLACs.h"
#include "S1AP_ForbiddenLAs-Item.h"
#include "S1AP_ForbiddenLAs.h"
#include "S1AP_ForbiddenTACs.h"
#include "S1AP_ForbiddenTAs-Item.h"
#include "S1AP_ForbiddenTAs.h"
#include "S1AP_GBR-QosInformation.h"
#include "S1AP_GERAN-Cell-ID.h"
#include "S1AP_GTP-TEID.h"
#include "S1AP_GUMMEI.h"
#include "S1AP_GUMMEIList.h"
#include "S1AP_GUMMEIType.h"
#include "S1AP_GWContextReleaseIndication.h"
#include "S1AP_Global-ENB-ID.h"
#include "S1AP_HFN.h"
#include "S1AP_HFNModified.h"
#include "S1AP_HFNforPDCP-SNlength18.h"
#include "S1AP_HandoverCancel.h"
#include "S1AP_HandoverCancelAcknowledge.h"
#include "S1AP_HandoverCommand.h"
#include "S1AP_HandoverFailure.h"
#include "S1AP_HandoverNotify.h"
#include "S1AP_HandoverPreparationFailure.h"
#include "S1AP_HandoverRequest.h"
#include "S1AP_HandoverRequestAcknowledge.h"
#include "S1AP_HandoverRequired.h"
#include "S1AP_HandoverRestrictionList.h"
#include "S1AP_HandoverType.h"
#include "S1AP_IMSI.h"
#include "S1AP_ImmediateMDT.h"
#include "S1AP_InformationOnRecommendedCellsAndENBsForPaging.h"
#include "S1AP_InitialContextSetupFailure.h"
#include "S1AP_InitialContextSetupRequest.h"
#include "S1AP_InitialContextSetupResponse.h"
#include "S1AP_InitialUEMessage.h"
#include "S1AP_InitiatingMessage.h"
#include "S1AP_IntegrityProtectionAlgorithms.h"
#include "S1AP_IntendedNumberOfPagingAttempts.h"
#include "S1AP_Inter-SystemInformationTransferType.h"
#include "S1AP_InterfacesToTrace.h"
#include "S1AP_KillAllWarningMessages.h"
#include "S1AP_KillRequest.h"
#include "S1AP_KillResponse.h"
#include "S1AP_L3-Information.h"
#include "S1AP_LAC.h"
#include "S1AP_LAI.h"
#include "S1AP_LHN-ID.h"
#include "S1AP_LPPa-PDU.h"
#include "S1AP_LastVisitedCell-Item.h"
#include "S1AP_LastVisitedEUTRANCellInformation.h"
#include "S1AP_LastVisitedGERANCellInformation.h"
#include "S1AP_LastVisitedUTRANCellInformation.h"
#include "S1AP_Links-to-log.h"
#include "S1AP_ListeningSubframePattern.h"
#include "S1AP_LocationReport.h"
#include "S1AP_LocationReportingControl.h"
#include "S1AP_LocationReportingFailureIndication.h"
#include "S1AP_LoggedMBSFNMDT.h"
#include "S1AP_LoggedMDT.h"
#include "S1AP_LoggingDuration.h"
#include "S1AP_LoggingInterval.h"
#include "S1AP_M-TMSI.h"
#include "S1AP_M1PeriodicReporting.h"
#include "S1AP_M1ReportingTrigger.h"
#include "S1AP_M1ThresholdEventA2.h"
#include "S1AP_M3Configuration.h"
#include "S1AP_M3period.h"
#include "S1AP_M4Configuration.h"
#include "S1AP_M4period.h"
#include "S1AP_M5Configuration.h"
#include "S1AP_M5period.h"
#include "S1AP_M6Configuration.h"
#include "S1AP_M6delay-threshold.h"
#include "S1AP_M6report-Interval.h"
#include "S1AP_M7Configuration.h"
#include "S1AP_M7period.h"
#include "S1AP_MBSFN-ResultToLog.h"
#include "S1AP_MBSFN-ResultToLogInfo.h"
#include "S1AP_MDT-Activation.h"
#include "S1AP_MDT-Configuration.h"
#include "S1AP_MDT-Location-Info.h"
#include "S1AP_MDTMode-Extension.h"
#include "S1AP_MDTMode.h"
#include "S1AP_MDTPLMNList.h"
#include "S1AP_MME-Code.h"
#include "S1AP_MME-Group-ID.h"
#include "S1AP_MME-UE-S1AP-ID.h"
#include "S1AP_MMECPRelocationIndication.h"
#include "S1AP_MMEConfigurationTransfer.h"
#include "S1AP_MMEConfigurationUpdate.h"
#include "S1AP_MMEConfigurationUpdateAcknowledge.h"
#include "S1AP_MMEConfigurationUpdateFailure.h"
#include "S1AP_MMEDirectInformationTransfer.h"
#include "S1AP_MMEPagingTarget.h"
#include "S1AP_MMERelaySupportIndicator.h"
#include "S1AP_MMEStatusTransfer.h"
#include "S1AP_MMEname.h"
#include "S1AP_MSClassmark2.h"
#include "S1AP_MSClassmark3.h"
#include "S1AP_ManagementBasedMDTAllowed.h"
#include "S1AP_Masked-IMEISV.h"
#include "S1AP_MeasurementThresholdA2.h"
#include "S1AP_MeasurementsToActivate.h"
#include "S1AP_MessageIdentifier.h"
#include "S1AP_MobilityInformation.h"
#include "S1AP_MutingAvailabilityIndication.h"
#include "S1AP_MutingPatternInformation.h"
#include "S1AP_NAS-PDU.h"
#include "S1AP_NASDeliveryIndication.h"
#include "S1AP_NASNonDeliveryIndication.h"
#include "S1AP_NASSecurityParametersfromE-UTRAN.h"
#include "S1AP_NASSecurityParameterstoE-UTRAN.h"
#include "S1AP_NB-IoT-DefaultPagingDRX.h"
#include "S1AP_NB-IoT-Paging-eDRX-Cycle.h"
#include "S1AP_NB-IoT-Paging-eDRXInformation.h"
#include "S1AP_NB-IoT-PagingTimeWindow.h"
#include "S1AP_NB-IoT-UEIdentityIndexValue.h"
#include "S1AP_NextPagingAreaScope.h"
#include "S1AP_NumberOfBroadcasts.h"
#include "S1AP_NumberofBroadcastRequest.h"
#include "S1AP_OldBSS-ToNewBSS-Information.h"
#include "S1AP_OverloadAction.h"
#include "S1AP_OverloadResponse.h"
#include "S1AP_OverloadStart.h"
#include "S1AP_OverloadStop.h"
#include "S1AP_PDCP-SN.h"
#include "S1AP_PDCP-SNExtended.h"
#include "S1AP_PDCP-SNlength18.h"
#include "S1AP_PLMNidentity.h"
#include "S1AP_PS-ServiceNotAvailable.h"
#include "S1AP_PWSFailureIndication.h"
#include "S1AP_PWSRestartIndication.h"
#include "S1AP_PWSfailedECGIList.h"
#include "S1AP_Paging-eDRX-Cycle.h"
#include "S1AP_Paging-eDRXInformation.h"
#include "S1AP_Paging.h"
#include "S1AP_PagingAttemptCount.h"
#include "S1AP_PagingAttemptInformation.h"
#include "S1AP_PagingDRX.h"
#include "S1AP_PagingPriority.h"
#include "S1AP_PagingTimeWindow.h"
#include "S1AP_PathSwitchRequest.h"
#include "S1AP_PathSwitchRequestAcknowledge.h"
#include "S1AP_PathSwitchRequestFailure.h"
#include "S1AP_PedestrianUE.h"
#include "S1AP_Port-Number.h"
#include "S1AP_Pre-emptionCapability.h"
#include "S1AP_Pre-emptionVulnerability.h"
#include "S1AP_Presence.h"
#include "S1AP_PriorityLevel.h"
#include "S1AP_PrivacyIndicator.h"
#include "S1AP_PrivateIE-Container.h"
#include "S1AP_PrivateIE-Field.h"
#include "S1AP_PrivateIE-ID.h"
#include "S1AP_PrivateMessage.h"
#include "S1AP_ProSeAuthorized.h"
#include "S1AP_ProSeDirectCommunication.h"
#include "S1AP_ProSeDirectDiscovery.h"
#include "S1AP_ProSeUEtoNetworkRelaying.h"
#include "S1AP_ProcedureCode.h"
#include "S1AP_ProtocolError-IE-ContainerList.h"
#include "S1AP_ProtocolExtensionContainer.h"
#include "S1AP_ProtocolExtensionField.h"
#include "S1AP_ProtocolExtensionID.h"
#include "S1AP_ProtocolIE-Container.h"
#include "S1AP_ProtocolIE-ContainerList.h"
#include "S1AP_ProtocolIE-ContainerPair.h"
#include "S1AP_ProtocolIE-ContainerPairList.h"
#include "S1AP_ProtocolIE-Field.h"
#include "S1AP_ProtocolIE-FieldPair.h"
#include "S1AP_ProtocolIE-ID.h"
#include "S1AP_ProtocolIE-SingleContainer.h"
#include "S1AP_QCI.h"
#include "S1AP_RAC.h"
#include "S1AP_RAT-Type.h"
#include "S1AP_RIMInformation.h"
#include "S1AP_RIMRoutingAddress.h"
#include "S1AP_RIMTransfer.h"
#include "S1AP_RLFReportInformation.h"
#include "S1AP_RNC-ID.h"
#include "S1AP_RRC-Container.h"
#include "S1AP_RRC-Establishment-Cause.h"
#include "S1AP_ReceiveStatusOfULPDCPSDUsExtended.h"
#include "S1AP_ReceiveStatusOfULPDCPSDUsPDCP-SNlength18.h"
#include "S1AP_ReceiveStatusofULPDCPSDUs.h"
#include "S1AP_RecommendedCellItem.h"
#include "S1AP_RecommendedCellList.h"
#include "S1AP_RecommendedCellsForPaging.h"
#include "S1AP_RecommendedENBItem.h"
#include "S1AP_RecommendedENBList.h"
#include "S1AP_RecommendedENBsForPaging.h"
#include "S1AP_RelativeMMECapacity.h"
#include "S1AP_RelayNode-Indicator.h"
#include "S1AP_RepetitionPeriod.h"
#include "S1AP_ReportAmountMDT.h"
#include "S1AP_ReportArea.h"
#include "S1AP_ReportIntervalMDT.h"
#include "S1AP_RequestType.h"
#include "S1AP_RerouteNASRequest.h"
#include "S1AP_Reset.h"
#include "S1AP_ResetAcknowledge.h"
#include "S1AP_ResetAll.h"
#include "S1AP_ResetType.h"
#include "S1AP_RetrieveUEInformation.h"
#include "S1AP_Routing-ID.h"
#include "S1AP_S-TMSI.h"
#include "S1AP_S1AP-PDU.h"
#include "S1AP_S1SetupFailure.h"
#include "S1AP_S1SetupRequest.h"
#include "S1AP_S1SetupResponse.h"
#include "S1AP_SONConfigurationTransfer.h"
#include "S1AP_SONInformation-Extension.h"
#include "S1AP_SONInformation.h"
#include "S1AP_SONInformationReply.h"
#include "S1AP_SONInformationReport.h"
#include "S1AP_SONInformationRequest.h"
#include "S1AP_SRVCCHOIndication.h"
#include "S1AP_SRVCCOperationNotPossible.h"
#include "S1AP_SRVCCOperationPossible.h"
#include "S1AP_SecurityContext.h"
#include "S1AP_SecurityKey.h"
#include "S1AP_SerialNumber.h"
#include "S1AP_ServedDCNs.h"
#include "S1AP_ServedDCNsItem.h"
#include "S1AP_ServedGUMMEIs.h"
#include "S1AP_ServedGUMMEIsItem.h"
#include "S1AP_ServedGroupIDs.h"
#include "S1AP_ServedMMECs.h"
#include "S1AP_ServedPLMNs.h"
#include "S1AP_Source-ToTarget-TransparentContainer.h"
#include "S1AP_SourceBSS-ToTargetBSS-TransparentContainer.h"
#include "S1AP_SourceOfUEActivityBehaviourInformation.h"
#include "S1AP_SourceRNC-ToTargetRNC-TransparentContainer.h"
#include "S1AP_SourceeNB-ID.h"
#include "S1AP_SourceeNB-ToTargeteNB-TransparentContainer.h"
#include "S1AP_StratumLevel.h"
#include "S1AP_SubscriberProfileIDforRFP.h"
#include "S1AP_SuccessfulOutcome.h"
#include "S1AP_SupportedTAs-Item.h"
#include "S1AP_SupportedTAs.h"
#include "S1AP_SynchronisationInformation.h"
#include "S1AP_SynchronisationStatus.h"
#include "S1AP_TABasedMDT.h"
#include "S1AP_TAC.h"
#include "S1AP_TAI-Broadcast-Item.h"
#include "S1AP_TAI-Broadcast.h"
#include "S1AP_TAI-Cancelled-Item.h"
#include "S1AP_TAI-Cancelled.h"
#include "S1AP_TAI.h"
#include "S1AP_TAIBasedMDT.h"
#include "S1AP_TAIItem.h"
#include "S1AP_TAIList.h"
#include "S1AP_TAIListForRestart.h"
#include "S1AP_TAIListforMDT.h"
#include "S1AP_TAIListforWarning.h"
#include "S1AP_TAListforMDT.h"
#include "S1AP_TBCD-STRING.h"
#include "S1AP_Target-ToSource-TransparentContainer.h"
#include "S1AP_TargetBSS-ToSourceBSS-TransparentContainer.h"
#include "S1AP_TargetID.h"
#include "S1AP_TargetRNC-ID.h"
#include "S1AP_TargetRNC-ToSourceRNC-TransparentContainer.h"
#include "S1AP_TargeteNB-ID.h"
#include "S1AP_TargeteNB-ToSourceeNB-TransparentContainer.h"
#include "S1AP_Threshold-RSRP.h"
#include "S1AP_Threshold-RSRQ.h"
#include "S1AP_Time-UE-StayedInCell-EnhancedGranularity.h"
#include "S1AP_Time-UE-StayedInCell.h"
#include "S1AP_TimeSynchronisationInfo.h"
#include "S1AP_TimeToWait.h"
#include "S1AP_TraceActivation.h"
#include "S1AP_TraceDepth.h"
#include "S1AP_TraceFailureIndication.h"
#include "S1AP_TraceStart.h"
#include "S1AP_TrafficLoadReductionIndication.h"
#include "S1AP_TransportInformation.h"
#include "S1AP_TransportLayerAddress.h"
#include "S1AP_TriggeringMessage.h"
#include "S1AP_TunnelInformation.h"
#include "S1AP_TypeOfError.h"
#include "S1AP_UE-HistoryInformation.h"
#include "S1AP_UE-HistoryInformationFromTheUE.h"
#include "S1AP_UE-RLF-Report-Container-for-extended-bands.h"
#include "S1AP_UE-RLF-Report-Container.h"
#include "S1AP_UE-RetentionInformation.h"
#include "S1AP_UE-S1AP-ID-pair.h"
#include "S1AP_UE-S1AP-IDs.h"
#include "S1AP_UE-Usage-Type.h"
#include "S1AP_UE-associatedLogicalS1-ConnectionItem.h"
#include "S1AP_UE-associatedLogicalS1-ConnectionListRes.h"
#include "S1AP_UE-associatedLogicalS1-ConnectionListResAck.h"
#include "S1AP_UEAggregateMaximumBitrate.h"
#include "S1AP_UECapabilityInfoIndication.h"
#include "S1AP_UEContextModificationConfirm.h"
#include "S1AP_UEContextModificationFailure.h"
#include "S1AP_UEContextModificationIndication.h"
#include "S1AP_UEContextModificationRequest.h"
#include "S1AP_UEContextModificationResponse.h"
#include "S1AP_UEContextReleaseCommand.h"
#include "S1AP_UEContextReleaseComplete.h"
#include "S1AP_UEContextReleaseRequest.h"
#include "S1AP_UEContextResumeFailure.h"
#include "S1AP_UEContextResumeRequest.h"
#include "S1AP_UEContextResumeResponse.h"
#include "S1AP_UEContextSuspendRequest.h"
#include "S1AP_UEContextSuspendResponse.h"
#include "S1AP_UEIdentityIndexValue.h"
#include "S1AP_UEInformationTransfer.h"
#include "S1AP_UEPagingID.h"
#include "S1AP_UERadioCapability.h"
#include "S1AP_UERadioCapabilityForPaging.h"
#include "S1AP_UERadioCapabilityMatchRequest.h"
#include "S1AP_UERadioCapabilityMatchResponse.h"
#include "S1AP_UESecurityCapabilities.h"
#include "S1AP_UESidelinkAggregateMaximumBitrate.h"
#include "S1AP_UEUserPlaneCIoTSupportIndicator.h"
#include "S1AP_UL-CP-SecurityInformation.h"
#include "S1AP_UL-NAS-Count.h"
#include "S1AP_UL-NAS-MAC.h"
#include "S1AP_UnsuccessfulOutcome.h"
#include "S1AP_UplinkNASTransport.h"
#include "S1AP_UplinkNonUEAssociatedLPPaTransport.h"
#include "S1AP_UplinkS1cdma2000tunnelling.h"
#include "S1AP_UplinkUEAssociatedLPPaTransport.h"
#include "S1AP_UserLocationInformation.h"
#include "S1AP_V2XServicesAuthorized.h"
#include "S1AP_VehicleUE.h"
#include "S1AP_VoiceSupportMatchIndicator.h"
#include "S1AP_WarningAreaList.h"
#include "S1AP_WarningMessageContents.h"
#include "S1AP_WarningSecurityInfo.h"
#include "S1AP_WarningType.h"
#include "S1AP_WriteReplaceWarningRequest.h"
#include "S1AP_WriteReplaceWarningResponse.h"
#include "S1AP_X2TNLConfigurationInfo.h"
#include "S1AP_asn_constant.h"

#define OGS_S1AP_INSIDE

#include "s1ap/conv.h"
#include "s1ap/message.h"

#undef OGS_S1AP_INSIDE

#ifdef __cplusplus
extern "C" {
#endif

extern int __ogs_s1ap_domain;

#undef OGS_LOG_DOMAIN
#define OGS_LOG_DOMAIN __ogs_s1ap_domain

#ifdef __cplusplus
}
#endif

#endif
