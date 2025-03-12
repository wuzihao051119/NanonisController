// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef TCLWRAPPER_H
#define TCLWRAPPER_H

#include <tcl.h>

#include "command.h"
#include "macro.h"

class TclWrapper {
public:
    TclWrapper() = delete;
    TclWrapper(const TclWrapper &) = delete;
    TclWrapper &operator=(const TclWrapper &) = delete;

    TclWrapper(Command &command);
    ~TclWrapper();
    void eval(const char *script);
    char *getResult();

private:
    AddTclCommands;

    void initTcl();
    void deleteTcl();
    void registerTclCommand();

private:
    Tcl_Interp *m_interp;
    Command &m_command;
};

#endif // TCLWRAPPER_H
