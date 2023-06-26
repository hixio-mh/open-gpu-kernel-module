/*
 * SPDX-FileCopyrightText: Copyright (c) 2020-2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <nvtypes.h>

//
// This file was generated with FINN, an NVIDIA coding tool.
// Source file:      ctrl/ctrlb0cc/ctrlb0ccinternal.finn
//

#include "ctrl/ctrlb0cc/ctrlb0ccbase.h"

#include "ctrl/ctrlb0cc/ctrlb0ccprofiler.h"        /* Some controls derivative of b0ccprofiler */
/*!
 * @ref NVB0CC_CTRL_CMD_ALLOC_PMA_STREAM
 */
#define NVB0CC_CTRL_CMD_INTERNAL_ALLOC_PMA_STREAM (0xb0cc0204) /* finn: Evaluated from "(FINN_MAXWELL_PROFILER_INTERNAL_INTERFACE_ID << 8) | NVB0CC_CTRL_INTERNAL_ALLOC_PMA_STREAM_PARAMS_MESSAGE_ID" */


// FINN PORT: The below type was generated by the FINN port to
// ensure that all API's have a unique structure associated
// with them!
#define NVB0CC_CTRL_CMD_INTERNAL_ALLOC_PMA_STREAM_FINN_PARAMS_MESSAGE_ID (0x0U)

typedef struct NVB0CC_CTRL_CMD_INTERNAL_ALLOC_PMA_STREAM_FINN_PARAMS {
    NV_DECLARE_ALIGNED(NVB0CC_CTRL_ALLOC_PMA_STREAM_PARAMS params, 8);
} NVB0CC_CTRL_CMD_INTERNAL_ALLOC_PMA_STREAM_FINN_PARAMS;



/*!
 * NVB0CC_CTRL_CMD_INTERNAL_PERMISSIONS_INIT
 *
 * This command is used to convey the client permissions for appropriate
 * profiling capability initialization
 */
#define NVB0CC_CTRL_CMD_INTERNAL_PERMISSIONS_INIT (0xb0cc0203) /* finn: Evaluated from "(FINN_MAXWELL_PROFILER_INTERNAL_INTERFACE_ID << 8) | NVB0CC_CTRL_INTERNAL_PERMISSIONS_INIT_PARAMS_MESSAGE_ID" */

#define NVB0CC_CTRL_INTERNAL_PERMISSIONS_INIT_PARAMS_MESSAGE_ID (0x3U)

typedef struct NVB0CC_CTRL_INTERNAL_PERMISSIONS_INIT_PARAMS {
    /*!
     * [in] Is Admin profiling permitted
     */
    NvBool bAdminProfilingPermitted;
    /*!
     * [in] Is Device profiling permitted
     */
    NvBool bDevProfilingPermitted;

    /*!
     * [in] Is Memory profiling permitted
     */
    NvBool bMemoryProfilingPermitted;
} NVB0CC_CTRL_INTERNAL_PERMISSIONS_INIT_PARAMS;

#define NVB0CC_CTRL_INTERNAL_ALLOC_PMA_STREAM_PARAMS_MESSAGE_ID (0x4U)

typedef struct NVB0CC_CTRL_INTERNAL_ALLOC_PMA_STREAM_PARAMS {
    /*!
     * [in] Memory handle (RW memory) for streaming records.
     * Size of this must be >= @ref pmaBufferOffset + @ref pmaBufferSize.
     */
    NvHandle hMemPmaBuffer;

    /*!
     * [in] Start offset of PMA buffer (offset in @ref hMemPmaBuffer).
     */
    NV_DECLARE_ALIGNED(NvU64 pmaBufferOffset, 8);

    /*!
     * [in] size of the buffer. This must be <= NVB0CC_PMA_BUFFER_SIZE_MAX.
     */
    NV_DECLARE_ALIGNED(NvU64 pmaBufferSize, 8);

    /*!
     * [in] Memory handle (RO memory) for streaming number of bytes available.
     * Size of this must be of at least @ref pmaBytesAvailableOffset +
     * @ref NVB0CC_PMA_BYTES_AVAILABLE_SIZE.
     */
    NvHandle hMemPmaBytesAvailable;

    /*!
     * [in] Start offset of PMA bytes available buffer (offset in @ref hMemPmaBytesAvailable).
     */
    NV_DECLARE_ALIGNED(NvU64 pmaBytesAvailableOffset, 8);

    /*!
     * [in] Enable ctxsw for PMA stream.
     */
    NvBool   ctxsw;

    /*!
     * [in/out] The PMA Channel Index associated with a given PMA stream.
     * This parameter is input when bInputPmaChIdx is true, else it's output parameter.
     */
    NvU32    pmaChannelIdx;

    /*!
     * [out] PMA buffer VA. Note that this is a HWPM Virtual address.
     */
    NV_DECLARE_ALIGNED(NvU64 pmaBufferVA, 8);

    /*!
    * [In] This field must be specified by the client to indicate whether the
    * pmaChannelIdx is input parameter or output parameter.
    */
    NvBool   bInputPmaChIdx;
} NVB0CC_CTRL_INTERNAL_ALLOC_PMA_STREAM_PARAMS;



/*!
 * NVB0CC_CTRL_CMD_INTERNAL_FREE_PMA_STREAM
 *
 * Internal logic for PMA Stream Free
 */
#define NVB0CC_CTRL_CMD_INTERNAL_FREE_PMA_STREAM (0xb0cc0206) /* finn: Evaluated from "(FINN_MAXWELL_PROFILER_INTERNAL_INTERFACE_ID << 8) | NVB0CC_CTRL_INTERNAL_FREE_PMA_STREAM_PARAMS_MESSAGE_ID" */

#define NVB0CC_CTRL_INTERNAL_FREE_PMA_STREAM_PARAMS_MESSAGE_ID (0x6U)

typedef struct NVB0CC_CTRL_INTERNAL_FREE_PMA_STREAM_PARAMS {
    /*!
     * [in] The PMA channel index associated with a given PMA stream.
     */
    NvU32 pmaChannelIdx;
} NVB0CC_CTRL_INTERNAL_FREE_PMA_STREAM_PARAMS;

/*!
 * NVB0CC_CTRL_CMD_INTERNAL_GET_MAX_PMAS
 *
 * Get the maximum number of PMA channels
 */
#define NVB0CC_CTRL_CMD_INTERNAL_GET_MAX_PMAS (0xb0cc0207) /* finn: Evaluated from "(FINN_MAXWELL_PROFILER_INTERNAL_INTERFACE_ID << 8) | NVB0CC_CTRL_INTERNAL_GET_MAX_PMAS_PARAMS_MESSAGE_ID" */

#define NVB0CC_CTRL_INTERNAL_GET_MAX_PMAS_PARAMS_MESSAGE_ID (0x7U)

typedef struct NVB0CC_CTRL_INTERNAL_GET_MAX_PMAS_PARAMS {
    /*!
     * [out] Max number of PMA channels
     */
    NvU32 maxPmaChannels;
} NVB0CC_CTRL_INTERNAL_GET_MAX_PMAS_PARAMS;

/*!
 * NVB0CC_CTRL_CMD_INTERNAL_BIND_PM_RESOURCES
 *
 * Internally bind PM resources.
 */
#define NVB0CC_CTRL_CMD_INTERNAL_BIND_PM_RESOURCES   (0xb0cc0208) /* finn: Evaluated from "(FINN_MAXWELL_PROFILER_INTERNAL_INTERFACE_ID << 8) | 0x8" */


/*!
 * NVB0CC_CTRL_CMD_INTERNAL_UNBIND_PM_RESOURCES
 *
 * Internally unbind PM resources.
 */
#define NVB0CC_CTRL_CMD_INTERNAL_UNBIND_PM_RESOURCES (0xb0cc0209) /* finn: Evaluated from "(FINN_MAXWELL_PROFILER_INTERNAL_INTERFACE_ID << 8) | 0x9" */

/*!
 * NVB0CC_CTRL_CMD_INTERNAL_RESERVE_HWPM_LEGACY
 *
 * Reserve legacy HWPM resources
 */
#define NVB0CC_CTRL_CMD_INTERNAL_RESERVE_HWPM_LEGACY (0xb0cc020a) /* finn: Evaluated from "(FINN_MAXWELL_PROFILER_INTERNAL_INTERFACE_ID << 8) | NVB0CC_CTRL_INTERNAL_RESERVE_HWPM_LEGACY_PARAMS_MESSAGE_ID" */

#define NVB0CC_CTRL_INTERNAL_RESERVE_HWPM_LEGACY_PARAMS_MESSAGE_ID (0xaU)

typedef struct NVB0CC_CTRL_INTERNAL_RESERVE_HWPM_LEGACY_PARAMS {
    /*!
     * [in] Enable ctxsw for HWPM.
     */
    NvBool ctxsw;
} NVB0CC_CTRL_INTERNAL_RESERVE_HWPM_LEGACY_PARAMS;

/* _ctrlb0ccinternal_h_ */
