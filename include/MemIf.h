/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/








#ifndef MEMIF_H_
#define MEMIF_H_
#define MEMIF_MODULE_ID			MODULE_ID_MEMIF
#define MEMIF_VENDOR_ID			1

#define MEMIF_SW_MAJOR_VERSION	1
#define MEMIF_SW_MINOR_VERSION	0
#define MEMIF_SW_PATCH_VERSION	0
#define MEMIF_AR_MAJOR_VERSION	3
#define MEMIF_AR_MINOR_VERSION	0
#define MEMIF_AR_PATCH_VERSION	1

#include "Std_Types.h"
#include "MemIf_Cfg.h"

#if (MEMIF_VERSION_INFO_API == STD_ON)
#define MemIf_GetVersionInfo(_vi) STD_GET_VERSION_INFO(_vi, MEMIF)
#endif /* MEMIF_VERSION_INFO_API */

#if (MEMIF_NUMBER_OF_DEVICES == 0)
#define MemIf_SetMode(_mode)
#define MemIf_Read(_deviceIndex,_blockNumber,_blockOffset,_dataBufferPtr,_length)
#define MemIf_Write(_deviceIndex,_blockNumber,_dataBufferPtr)
#define MemIf_Cancel(_deviceIndex)
#define MemIf_GetStatus(_deviceIndex)
#define MemIf_GetJobResult(_deviceIndex)
#define MemIf_InvalidateBlock(_deviceIndex,_blockNumber)
#define MemIf_EraseImmediateBlock(_deviceIndex,_blockNumber)
#endif

#if (MEMIF_NUMBER_OF_DEVICES == 1)
#if (MEMIF_DEVICE_TO_USE == FLS_DRIVER_INDEX)
#include "Fee.h"

#define MemIf_SetMode(_mode)	Fee_SetMode(_mode)
#define MemIf_Read(_deviceIndex,_blockNumber,_blockOffset,_dataBufferPtr,_length)	Fee_Read(_blockNumber,_blockOffset,_dataBufferPtr,_length)
#define MemIf_Write(_deviceIndex,_blockNumber,_dataBufferPtr)	Fee_Write(_blockNumber,_dataBufferPtr)
#define MemIf_Cancel(_deviceIndex)	Fee_Cancel()
#define MemIf_GetStatus(_deviceIndex)	Fee_GetStatus()
#define MemIf_GetJobResult(_deviceIndex)	Fee_GetJobResult()
#define MemIf_InvalidateBlock(_deviceIndex,_blockNumber)	Fee_InvalidateBlock(blockNumber)
#define MemIf_EraseImmediateBlock(_deviceIndex,_blockNumber)	Fee_EraseImmediateBlock(_blockNumber)

#elif (MEMIF_DEVICE_TO_USE == EEP_DRIVER_INDEX)
#include "Ea.h"

#define MemIf_SetMode(_mode)	Ea_SetMode(_mode)
#define MemIf_Read(_deviceIndex,_blockNumber,_blockOffset,_dataBufferPtr,_length)	Ea_Read(_blockNumber,_blockOffset,_dataBufferPtr,_length)
#define MemIf_Write(_deviceIndex,_blockNumber,_dataBufferPtr)	Ea_Write(_blockNumber,_dataBufferPtr)
#define MemIf_Cancel(_deviceIndex)	Ea_Cancel()
#define MemIf_GetStatus(_deviceIndex)	Ea_GetStatus()
#define MemIf_GetJobResult(_deviceIndex)	Ea_GetJobResult()
#define MemIf_InvalidateBlock(_deviceIndex,_blockNumber)	Ea_InvalidateBlock(_blockNumber)
#define MemIf_EraseImmediateBlock(_deviceIndex,_blockNumber)	Ea_EraseImmediateBlock(_blockNumber)
#else
#error "Memory device unknown (MEMIF_DEVICE_TO_USE)"
#endif

#endif

#if (MEMIF_NUMBER_OF_DEVICES > 1)
#error "Support for more than one device is not implemented yet!"
void MemIf_SetMode(MemIf_ModeType Mode);
Std_ReturnType MemIf_Read(uint8 DeviceIndex, uint16 BlockNumber, uint16 BlockOffset, uint8 *DataBufferPtr, uint16 Length);
Std_ReturnType MemIf_Write(uint8 DeviceIndex, uint16 BlockNumber, uint8 *DataBufferPtr);
void MemIf_Cancel(uint8 DeviceIndex);
MemIf_StatusType MemIf_GetStatus(uint8 DeviceIndex);
MemIf_JobResultType MemIf_GetJobResult(uint8 DeviceIndex);
Std_ReturnType MemIf_InvalidateBlock(uint8 DeviceIndex, uint16 BlockNumber);
Std_ReturnType MemIf_EraseImmediateBlock(uint8 DeviceIndex, uint16 BlockNumber);
#endif

#endif /*MEMIF_H_*/
