// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef TCLWRAPPER_H
#define TCLWRAPPER_H

#include <tcl.h>

#include "tclpipe.h"

class TclWrapper {
public:
    TclWrapper() = delete;
    TclWrapper(const TclWrapper &) = delete;
    TclWrapper &operator=(const TclWrapper &) = delete;

    TclWrapper(pTclPipes pipes);
    ~TclWrapper();
    
private:
    int BiasGet(Tcl_Interp *interp, int objc, Tcl_Obj *const *objv);
    int BiasSet(Tcl_Interp *interp, int objc, Tcl_Obj *const *objv);

    void initTcl();
    void deleteTcl();
    void registerCommand();
    void registerChannel();

private:
    Tcl_Interp *m_interp;
    pTclPipes m_pipes;
};

#endif // TCLWRAPPER_H
