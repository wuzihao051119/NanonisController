// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "tclcommand.h"

#define wrapper(Func) \
    [](ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) { \
        return reinterpret_cast<TclCommand *>(clientData)->Func(interp, objc, objv); \
    }

TclCommand::TclCommand(Tcl_Interp *interp) : m_interp(interp) {
    initTcl();
    registerCommand();
}

TclCommand::~TclCommand() {
    deleteTcl();
}

int TclCommand::initTcl() {
    return Tcl_Init(m_interp) ? TCL_ERROR : TCL_OK;
}

void TclCommand::deleteTcl() {
    Tcl_DeleteInterp(m_interp);
}

void TclCommand::registerCommand() {
    Tcl_Command ret1 = Tcl_CreateObjCommand(m_interp, "Bias.Set", wrapper(BiasSet), this, NULL);
    Tcl_Command ret2 = Tcl_CreateObjCommand(m_interp, "Bias.Get", wrapper(BiasGet), this, NULL);
}

int TclCommand::BiasSet(Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
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

int TclCommand::BiasGet(Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) {
    return TCL_OK;
}
