// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include <thread>

#include <tcl.h>
#include <Windows.h>

CHAR pCh[50];
HANDLE readPipe, writePipe;

void readPipeFunc() {
    while (true) {
        DWORD dwRead = 0;
        ReadFile(readPipe, pCh, 50, &dwRead, NULL);
        if (dwRead != 0)
            DebugBreak();
    }
}

int Tcl_AppInit(Tcl_Interp *interp) {
    Tcl_Init(interp);

    Tcl_Channel stdoutChannel = Tcl_GetChannel(interp, "stdout", NULL);
    Tcl_UnregisterChannel(interp, stdoutChannel);

    Tcl_Channel outPipeChannel = Tcl_MakeFileChannel(writePipe, TCL_WRITABLE);
    Tcl_RegisterChannel(interp, outPipeChannel);

    return TCL_OK;
}

int main(int argc, char *argv[]) {
    CreatePipe(&readPipe, &writePipe, NULL, 0);

    std::thread read(readPipeFunc);

    Tcl_Main(argc, argv, Tcl_AppInit);
}
