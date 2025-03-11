// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "tclpipe.h"

TclPipe::TclPipe() {
    if (!CreatePipe(&hTclInReadPipe, &hTclInWritePipe, NULL, 0))
        return;

    tclInWritePipe = _fdopen(_open_osfhandle((intptr_t)hTclInWritePipe, _O_TEXT), "w");
    
    if (!CreatePipe(&hTclOutReadPipe, &hTclOutWritePipe, NULL, 0))
        return;

    tclOutReadPipe = _fdopen(_open_osfhandle((intptr_t)hTclOutReadPipe, _O_TEXT), "r");
}

TclPipe::~TclPipe() {
    CloseHandle(hTclInReadPipe);
    fclose(tclInWritePipe);
    fclose(tclOutReadPipe);
    CloseHandle(hTclOutWritePipe);
}

pTclPipes TclPipe::getTclPipes() {
    return new tclPipes { hTclInReadPipe, tclInWritePipe, tclOutReadPipe, hTclOutWritePipe };
}
