// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "tclwrapper.h"

#define CallbackWrapper(Func) \
    [](ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) { \
        return reinterpret_cast<TclWrapper *>(clientData)->Func(interp, objc, objv); \
    }

TclWrapper::TclWrapper(pTclPipes pipes) : m_pipes(pipes) {
    initTcl();
    registerCommand();
     registerChannel();
}

TclWrapper::~TclWrapper() {
    deleteTcl();
}

void TclWrapper::initTcl() {
    m_interp = Tcl_CreateInterp();
    Tcl_Init(m_interp);
}

void TclWrapper::deleteTcl() {
    Tcl_DeleteInterp(m_interp);
}

void TclWrapper::registerCommand() {
    Tcl_Command ret1 = Tcl_CreateObjCommand(m_interp, "Bias.Set", CallbackWrapper(BiasSet), this, NULL);
    Tcl_Command ret2 = Tcl_CreateObjCommand(m_interp, "Bias.Get", CallbackWrapper(BiasGet), this, NULL);
}

void TclWrapper::registerChannel() {
    Tcl_Channel inChannel = Tcl_MakeFileChannel(m_pipes->hTclInReadPipe, TCL_READABLE);
    Tcl_Channel outChannel = Tcl_MakeFileChannel(m_pipes->hTclOutWritePipe, TCL_WRITABLE);
    Tcl_Channel errChannel = Tcl_MakeFileChannel(m_pipes->hTclOutWritePipe, TCL_WRITABLE);
    Tcl_RegisterChannel(m_interp, inChannel);
    Tcl_RegisterChannel(m_interp, outChannel);
    Tcl_RegisterChannel(m_interp, errChannel);
}

int TclWrapper::BiasSet(Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
    if (objc != 2) {
        Tcl_WrongNumArgs(interp, 1, objv, "?Bias_value");
        return TCL_ERROR;
    }

    Tcl_Size length;
    char *str = Tcl_GetStringFromObj(objv[1], &length);
    Tcl_Obj *result = Tcl_NewStringObj(str, length);
    Tcl_SetObjResult(interp, result);

    return TCL_OK;
}

int TclWrapper::BiasGet(Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
    return TCL_OK;
}
