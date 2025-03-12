// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "tclwrapper.h"

#define CallbackWrapper(Func) \
    [](ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) { \
        return reinterpret_cast<TclWrapper *>(clientData)->Func(interp, objc, objv); \
    }

TclWrapper::TclWrapper(Command &command) : m_command(command) {
    initTcl();
    registerTclCommand();
}

TclWrapper::~TclWrapper() {
    deleteTcl();
}

void TclWrapper::eval(const char *script) {
    Tcl_Eval(m_interp, script);
}

char *TclWrapper::getResult() {
    return Tcl_GetObjResult(m_interp)->bytes;
}

void TclWrapper::initTcl() {
    m_interp = Tcl_CreateInterp();
    Tcl_Init(m_interp);
}

void TclWrapper::deleteTcl() {
    Tcl_DeleteInterp(m_interp);
}

void TclWrapper::registerTclCommand() {
    RegisterTclCommands;
}
