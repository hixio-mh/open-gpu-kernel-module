// This file is automatically generated by rmconfig - DO NOT EDIT!
//
// Profile:  shipping-gpus-openrm
// Template: templates/gt_eng_iom.c
//
#include "nvstatus.h"
#include "nvport/inline/util_valist.h"
#include "nvport/nvport.h"
#include "core/core.h"
#include "nvoc/rtti.h"
#include "os/os.h"
#include "gpu/gpu.h"

#include "objrpc.h"

#include "g_rpc_private.h"

//
// RPC's object-level _STUB, _MISSING, _VGPUSTUB interface routines
// (if any)
//








//
// Initialize RPC's object-level interfaces
//
void rpcObjIfacesSetup(OBJRPC *pRpc)
{
    RPC_OBJ_IFACES *pRpcMethods = &pRpc->obj;
    pRpcMethods->__rpcConstruct__             = rpcConstruct_IMPL;
    pRpcMethods->__rpcDestroy__               = rpcDestroy_IMPL;
    pRpcMethods->__rpcSendMessage__           = rpcSendMessage_IMPL;
    pRpcMethods->__rpcRecvPoll__              = rpcRecvPoll_IMPL;
 //     pRpcMethods->__rpcSendMessageUvm__        = rpcSendMessageUvm_IMPL; # ONLY_IF => VIRTUALIZATION
 //     pRpcMethods->__rpcRecvPollUvm__           = rpcRecvPollUvm_IMPL; # ONLY_IF => VIRTUALIZATION
}

static void
rpcSetPropertiesSpecial
(
    POBJRPC    pRpc
)
{

}





//
// RPC's run-time type information
//

extern const struct NVOC_CLASS_DEF __iom_class_def_OBJRPC;

void      __iom_dtor_OBJRPC(POBJRPC);

const struct NVOC_RTTI __iom_rtti_OBJRPC_OBJRPC =
{
    &__iom_class_def_OBJRPC,
    (NVOC_DYNAMIC_DTOR)&__iom_dtor_OBJRPC,
    0,
};

static const struct NVOC_CASTINFO __iom_castinfo_OBJRPC =
{
    1,
    {
        &__iom_rtti_OBJRPC_OBJRPC
    }
};

extern const NVOC_RTTI_PROVIDER __iom_rtti_provider;
const struct NVOC_CLASS_DEF __iom_class_def_OBJRPC =
{
    {
        sizeof(OBJRPC),
        classId(OBJRPC),
        &__iom_rtti_provider,
#if NV_PRINTF_STRINGS_ALLOWED
        "OBJRPC",
#endif
    },
    NULL,
    &__iom_castinfo_OBJRPC,
};




//
// RPC's object infrastructure boilerplate
//

// initializers, constructors, and destructors for RPC's base classes

NV_STATUS __iom_ctor_OBJRPC(POBJRPC pRpc)
{
    RMCFG_MODULE_ENABLED_OR_ASSERT_AND_BAIL(RPC);
    return NV_OK;
}

NV_STATUS __iom_vctor_OBJRPC(Dynamic *pDynamic, va_list args)
{
    NV_STATUS status;
    POBJRPC pThis = dynamicCast(pDynamic, OBJRPC);
    if (pThis != NULL)
    {
        status = __iom_ctor_OBJRPC(pThis);
    }
    else
    {
        status = NV_ERR_INVALID_OBJECT;
    }
    return status;
}

void __iom_dtor_OBJRPC(POBJRPC pRpc)
{
}

// RPC's object initializer function to set up vtables and RTTI
void __iom_init_OBJRPC(POBJRPC pRpc)
{
    rpcObjIfacesSetup(pRpc);
    rpcSetPropertiesSpecial(pRpc);
}


//
// RPC's object creation routine
//

