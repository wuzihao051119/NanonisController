// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "tclcommand.h"

int Tcl_AppInit(Tcl_Interp *interp) {
    TclCommand *command = new TclCommand(interp);
    return TCL_OK;
}

int main(int argc, char *argv[]) {
    Tcl_Main(argc, argv, Tcl_AppInit);
    return 0;
}
