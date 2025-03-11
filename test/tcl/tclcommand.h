#ifndef TCLCOMMAND_H
#define TCLCOMMAND_H

#include <tcl.h>

class TclCommand {
public:
    TclCommand(Tcl_Interp *interp);
    ~TclCommand();
    
private:
    int BiasGet(Tcl_Interp *interp, int objc, Tcl_Obj *const *objv);
    int BiasSet(Tcl_Interp *interp, int objc, Tcl_Obj *const *objv);

    int initTcl();
    void deleteTcl();
    void registerCommand();

private:
    Tcl_Interp *m_interp;
};

#endif // TCLCOMMAND_H
