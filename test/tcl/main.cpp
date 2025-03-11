#include "tclcommand.h"

int Tcl_AppInit(Tcl_Interp *interp) {
    TclCommand *command = new TclCommand(interp);
    return TCL_OK;
}

int main(int argc, char *argv[]) {
    Tcl_Main(argc, argv, Tcl_AppInit);
    return 0;
}
