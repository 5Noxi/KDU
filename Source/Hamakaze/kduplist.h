/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2020 - 2023
*
*  TITLE:       KDUPLIST.H
*
*  VERSION:     1.32
*
*  DATE:        10 Jun 2023
*
*  Providers global list.
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
* ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
*******************************************************************************/

#pragma once

#include "idrv/nal.h"
#include "idrv/rtcore.h"
#include "idrv/mapmem.h"
#include "idrv/atszio.h"
#include "idrv/winio.h"
#include "idrv/winring0.h"
#include "idrv/phymem.h"
#include "idrv/lha.h"
#include "idrv/directio64.h"
#include "idrv/gmer.h"
#include "idrv/dell.h"
#include "idrv/mimidrv.h"
#include "idrv/kph.h"
#include "idrv/procexp.h"
#include "idrv/dbk.h"
#include "idrv/marvinhw.h"
#include "idrv/zemana.h"
#include "idrv/asrdrv.h"
#include "idrv/alcpu.h"
#include "idrv/ryzen.h"
#include "idrv/hilscher.h"
#include "idrv/lenovo.h"
#include "idrv/hp.h"
#include "idrv/zodiacon.h"

//
// Victims public array.
//
static KDU_VICTIM_PROVIDER g_KDUVictims[] = {
    {
        (LPCWSTR)PROCEXP152,              // Device and driver name,
        (LPCWSTR)PROCEXP1627_DESC,        // Description
        IDR_PROCEXP1627,                  // Resource id in drivers database
        KDU_VICTIM_PE1627,                // Victim id
        SYNCHRONIZE |
        GENERIC_READ | GENERIC_WRITE,     // Desired access flags used for acquiring victim handle
        KDU_VICTIM_FLAGS_SUPPORT_RELOAD,  // Victim flags, target dependent
        VpCreateCallback,                 // Victim create callback
        VpReleaseCallback,                // Victim release callback
        VpExecuteCallback,                // Victim execute payload callback
        &g_ProcExpSig,                    // Victim dispatch bytes
        sizeof(g_ProcExpSig)              // Victim dispatch bytes size
    },

    {
        (LPCWSTR)PROCEXP152,              // Device and driver name,
        (LPCWSTR)PROCEXP1702_DESC,        // Description
        IDR_PROCEXP1702,                  // Resource id in drivers database
        KDU_VICTIM_PE1702,                // Victim id
        SYNCHRONIZE |
        GENERIC_READ | GENERIC_WRITE,     // Desired access flags used for acquiring victim handle
        KDU_VICTIM_FLAGS_SUPPORT_RELOAD,  // Victim flags, target dependent
        VpCreateCallback,                 // Victim create callback
        VpReleaseCallback,                // Victim release callback
        VpExecuteCallback,                // Victim execute payload callback
        &g_ProcExpSig,                    // Victim dispatch bytes
        sizeof(g_ProcExpSig)              // Victim dispatch bytes size
    }

};

//
// Providers public array, unsupported methods must be set to NULL.
//
static KDU_PROVIDER g_KDUProviders[] =
{
    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)NalReadVirtualMemoryEx,
        (provWriteKernelVM)NalWriteVirtualMemoryEx,

        (provVirtualToPhysical)NalVirtualToPhysical,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)NULL,
        (provWritePhysicalMemory)NULL,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)RTCoreReadVirtualMemory,
        (provWriteKernelVM)RTCoreWriteVirtualMemory,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)NULL,
        (provWritePhysicalMemory)NULL,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)MapMemRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)MapMemReadKernelVirtualMemory,
        (provWriteKernelVM)MapMemWriteKernelVirtualMemory,

        (provVirtualToPhysical)MapMemVirtualToPhysical,
        (provQueryPML4)MapMemQueryPML4Value,
        (provReadPhysicalMemory)MapMemReadPhysicalMemory,
        (provWritePhysicalMemory)MapMemWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)AtszioReadKernelVirtualMemory,
        (provWriteKernelVM)AtszioWriteKernelVirtualMemory,

        (provVirtualToPhysical)AtszioVirtualToPhysical,
        (provQueryPML4)AtszioQueryPML4Value,
        (provReadPhysicalMemory)AtszioReadPhysicalMemory,
        (provWritePhysicalMemory)AtszioWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)WinIoRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)WinIoReadKernelVirtualMemory,
        (provWriteKernelVM)WinIoWriteKernelVirtualMemory,

        (provVirtualToPhysical)WinIoVirtualToPhysical,
        (provQueryPML4)WinIoQueryPML4Value,
        (provReadPhysicalMemory)WinIoReadPhysicalMemory,
        (provWritePhysicalMemory)WinIoWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)WinIoRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)WinIoReadKernelVirtualMemory,
        (provWriteKernelVM)WinIoWriteKernelVirtualMemory,

        (provVirtualToPhysical)WinIoVirtualToPhysical,
        (provQueryPML4)WinIoQueryPML4Value,
        (provReadPhysicalMemory)WinIoReadPhysicalMemory,
        (provWritePhysicalMemory)WinIoWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)WinIoRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)WinIoReadKernelVirtualMemory,
        (provWriteKernelVM)WinIoWriteKernelVirtualMemory,

        (provVirtualToPhysical)WinIoVirtualToPhysical,
        (provQueryPML4)WinIoQueryPML4Value,
        (provReadPhysicalMemory)WinIoReadPhysicalMemory,
        (provWritePhysicalMemory)WinIoWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)WRZeroReadKernelVirtualMemory,
        (provWriteKernelVM)WRZeroWriteKernelVirtualMemory,

        (provVirtualToPhysical)WRZeroVirtualToPhysical,
        (provQueryPML4)WRZeroQueryPML4Value,
        (provReadPhysicalMemory)WRZeroReadPhysicalMemory,
        (provWritePhysicalMemory)WRZeroWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)WinIoRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)WinIoReadKernelVirtualMemory,
        (provWriteKernelVM)WinIoWriteKernelVirtualMemory,

        (provVirtualToPhysical)WinIoVirtualToPhysical,
        (provQueryPML4)WinIoQueryPML4Value,
        (provReadPhysicalMemory)WinIoReadPhysicalMemory,
        (provWritePhysicalMemory)WinIoWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)WinIoRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)WinIoReadKernelVirtualMemory,
        (provWriteKernelVM)WinIoWriteKernelVirtualMemory,

        (provVirtualToPhysical)WinIoVirtualToPhysical,
        (provQueryPML4)WinIoQueryPML4Value,
        (provReadPhysicalMemory)WinIoReadPhysicalMemory,
        (provWritePhysicalMemory)WinIoWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)PhyMemReadKernelVirtualMemory,
        (provWriteKernelVM)PhyMemWriteKernelVirtualMemory,

        (provVirtualToPhysical)PhyMemVirtualToPhysical,
        (provQueryPML4)PhyMemQueryPML4Value,
        (provReadPhysicalMemory)PhyMemReadPhysicalMemory,
        (provWritePhysicalMemory)PhyMemWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)WinIoRegisterDriver,
        (provUnregisterDriver)WinIoUnregisterDriver,
        (provPreOpenDriver)WinIoPreOpen,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)WinIoReadKernelVirtualMemory,
        (provWriteKernelVM)WinIoWriteKernelVirtualMemory,

        (provVirtualToPhysical)WinIoVirtualToPhysical,
        (provQueryPML4)WinIoQueryPML4Value,
        (provReadPhysicalMemory)WinIoReadPhysicalMemory,
        (provWritePhysicalMemory)WinIoWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)LHAReadKernelVirtualMemory,
        (provWriteKernelVM)LHAWriteKernelVirtualMemory,

        (provVirtualToPhysical)LHAVirtualToPhysical,
        (provQueryPML4)LHAQueryPML4Value,
        (provReadPhysicalMemory)LHAReadPhysicalMemory,
        (provWritePhysicalMemory)LHAWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)WinIoRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)WinIoReadKernelVirtualMemory,
        (provWriteKernelVM)WinIoWriteKernelVirtualMemory,

        (provVirtualToPhysical)WinIoVirtualToPhysical,
        (provQueryPML4)WinIoQueryPML4Value,
        (provReadPhysicalMemory)WinIoReadPhysicalMemory,
        (provWritePhysicalMemory)WinIoWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)DI64ReadKernelVirtualMemory,
        (provWriteKernelVM)DI64WriteKernelVirtualMemory,

        (provVirtualToPhysical)DI64VirtualToPhysical,
        (provQueryPML4)DI64QueryPML4Value,
        (provReadPhysicalMemory)DI64ReadPhysicalMemory,
        (provWritePhysicalMemory)DI64WritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)GmerRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)NULL,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)GmerReadVirtualMemory,
        (provWriteKernelVM)GmerWriteVirtualMemory,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)NULL,
        (provWritePhysicalMemory)NULL,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)DbUtilReadVirtualMemory,
        (provWriteKernelVM)DbUtilWriteVirtualMemory,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)NULL,
        (provWritePhysicalMemory)NULL,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)MimidrvReadVirtualMemory,
        (provWriteKernelVM)MimidrvWriteVirtualMemory,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)NULL,
        (provWritePhysicalMemory)NULL,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)KphRegisterDriver,
        (provUnregisterDriver)KphUnregisterDriver,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)NULL,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)KphReadKernelVirtualMemory,
        (provWriteKernelVM)KphWriteKernelVirtualMemory,

        (provVirtualToPhysical)KphVirtualToPhysical,
        (provQueryPML4)KphQueryPML4Value,
        (provReadPhysicalMemory)KphReadPhysicalMemory,
        (provWritePhysicalMemory)KphWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)PexRegisterDriver,
        (provUnregisterDriver)PexpUnregisterDriver,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)NULL,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)PexReadKernelVirtualMemory,
        (provWriteKernelVM)PexWriteKernelVirtualMemory,

        (provVirtualToPhysical)PexVirtualToPhysical,
        (provQueryPML4)PexQueryPML4Value,
        (provReadPhysicalMemory)PexReadPhysicalMemory,
        (provWritePhysicalMemory)PexWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)DbUtilStartVulnerableDriver,
        (provStopVulnerableDriver)DbUtilStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)DbUtilReadVirtualMemory,
        (provWriteKernelVM)DbUtilWriteVirtualMemory,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)NULL,
        (provWritePhysicalMemory)NULL,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)DbkStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)NULL,
        (provMapDriver)DbkMapDriver,
        (provControlDSE)DbkControlDSE,

        (provReadKernelVM)NULL,
        (provWriteKernelVM)NULL,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)NULL,
        (provWritePhysicalMemory)NULL,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)WinIoRegisterDriver,
        (provUnregisterDriver)AsusIO3UnregisterDriver,
        (provPreOpenDriver)AsusIO3PreOpen,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)WinIoReadKernelVirtualMemory,
        (provWriteKernelVM)WinIoWriteKernelVirtualMemory,

        (provVirtualToPhysical)WinIoVirtualToPhysical,
        (provQueryPML4)WinIoQueryPML4Value,
        (provReadPhysicalMemory)WinIoReadPhysicalMemory,
        (provWritePhysicalMemory)WinIoWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)HwReadKernelVirtualMemory,
        (provWriteKernelVM)HwWriteKernelVirtualMemory,

        (provVirtualToPhysical)HwVirtualToPhysical,
        (provQueryPML4)HwQueryPML4Value,
        (provReadPhysicalMemory)HwReadPhysicalMemory,
        (provWritePhysicalMemory)HwWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)MapMemRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)MapMemReadKernelVirtualMemory,
        (provWriteKernelVM)MapMemWriteKernelVirtualMemory,

        (provVirtualToPhysical)MapMemVirtualToPhysical,
        (provQueryPML4)MapMemQueryPML4Value,
        (provReadPhysicalMemory)MapMemReadPhysicalMemory,
        (provWritePhysicalMemory)MapMemWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)ZmRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)NULL,
        (provMapDriver)ZmMapDriver,
        (provControlDSE)ZmControlDSE,

        (provReadKernelVM)NULL,
        (provWriteKernelVM)NULL,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)NULL,
        (provWritePhysicalMemory)NULL,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)WinIoRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)WinIoReadKernelVirtualMemory,
        (provWriteKernelVM)WinIoWriteKernelVirtualMemory,

        (provVirtualToPhysical)WinIoVirtualToPhysical,
        (provQueryPML4)WinIoQueryPML4Value,
        (provReadPhysicalMemory)WinIoReadPhysicalMemory,
        (provWritePhysicalMemory)WinIoWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)DI64ReadKernelVirtualMemory,
        (provWriteKernelVM)DI64WriteKernelVirtualMemory,

        (provVirtualToPhysical)DI64VirtualToPhysical,
        (provQueryPML4)DI64QueryPML4Value,
        (provReadPhysicalMemory)DI64ReadPhysicalMemory,
        (provWritePhysicalMemory)DI64WritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE2,

        (provReadKernelVM)NULL,
        (provWriteKernelVM)NULL,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)AsrReadPhysicalMemory,
        (provWritePhysicalMemory)AsrWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE2,

        (provReadKernelVM)NULL,
        (provWriteKernelVM)NULL,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)AlcReadPhysicalMemory,
        (provWritePhysicalMemory)AlcWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE2,

        (provReadKernelVM)NULL,
        (provWriteKernelVM)NULL,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)RmReadPhysicalMemory,
        (provWritePhysicalMemory)RmWritePhysicalMemory,

        (provValidatePrerequisites)RmValidatePrerequisites
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)PhmRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE2,

        (provReadKernelVM)NULL,
        (provWriteKernelVM)NULL,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)PhmReadPhysicalMemory,
        (provWritePhysicalMemory)PhmWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)LddRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)LddControlDSE,

        (provReadKernelVM)LddReadKernelVirtualMemory,
        (provWriteKernelVM)LddWriteKernelVirtualMemory,

        (provVirtualToPhysical)LddpVirtualToPhysical,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)LddReadWritePhysicalMemoryStub,
        (provWritePhysicalMemory)LddReadWritePhysicalMemoryStub,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)DellRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE2,

        (provReadKernelVM)NULL,
        (provWriteKernelVM)NULL,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)DpdReadPhysicalMemory,
        (provWritePhysicalMemory)DpdWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)WinIoRegisterDriver,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)WinIoReadKernelVirtualMemory,
        (provWriteKernelVM)WinIoWriteKernelVirtualMemory,

        (provVirtualToPhysical)WinIoVirtualToPhysical,
        (provQueryPML4)WinIoQueryPML4Value,
        (provReadPhysicalMemory)WinIoReadPhysicalMemory,
        (provWritePhysicalMemory)WinIoWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)HpEtdReadVirtualMemory,
        (provWriteKernelVM)HpEtdWriteVirtualMemory,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)NULL,
        (provWritePhysicalMemory)NULL,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)KDUProvStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)NULL,
        (provUnregisterDriver)NULL,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)KDUProviderPostOpen,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)KObExpReadVirtualMemory,
        (provWriteKernelVM)KObExpWriteVirtualMemory,

        (provVirtualToPhysical)NULL,
        (provQueryPML4)NULL,
        (provReadPhysicalMemory)NULL,
        (provWritePhysicalMemory)NULL,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)ZdcStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)ZdcRegisterDriver,
        (provUnregisterDriver)ZdcUnregisterDriver,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)NULL,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)ZdcReadKernelVirtualMemory,
        (provWriteKernelVM)ZdcWriteKernelVirtualMemory,

        (provVirtualToPhysical)ZdcVirtualToPhysical,
        (provQueryPML4)ZdcQueryPML4Value,
        (provReadPhysicalMemory)ZdcReadPhysicalMemory,
        (provWritePhysicalMemory)ZdcWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    },

    {
        NULL,

        (provStartVulnerableDriver)ZdcStartVulnerableDriver,
        (provStopVulnerableDriver)KDUProvStopVulnerableDriver,

        (provRegisterDriver)ZdcRegisterDriver,
        (provUnregisterDriver)ZdcUnregisterDriver,
        (provPreOpenDriver)NULL,
        (provPostOpenDriver)NULL,
        (provMapDriver)KDUMapDriver,
        (provControlDSE)KDUControlDSE,

        (provReadKernelVM)ZdcReadKernelVirtualMemory,
        (provWriteKernelVM)ZdcWriteKernelVirtualMemory,

        (provVirtualToPhysical)ZdcVirtualToPhysical,
        (provQueryPML4)ZdcQueryPML4Value,
        (provReadPhysicalMemory)ZdcReadPhysicalMemory,
        (provWritePhysicalMemory)ZdcWritePhysicalMemory,

        (provValidatePrerequisites)NULL
    }
};
