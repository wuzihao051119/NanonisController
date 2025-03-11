// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "tclpipe.h"

TclPipe::TclPipe() {
    if (!CreatePipe(&hTclInReadPipe, &hTclInWritePipe, NULL, 0))
        return;
    
    tclInRead = _fdopen(_open_osfhandle((intptr_t)hTclInReadPipe, _O_TEXT), "r");
    tclInWrite = _fdopen(_open_osfhandle((intptr_t)hTclInWritePipe, _O_TEXT), "w");
    
    if (CreatePipe(&hTclOutReadPipe, &hTclOutWritePipe, NULL, 0))
        return;

    tclOutRead = _fdopen(_open_osfhandle((intptr_t)hTclOutReadPipe, _O_TEXT), "r");
    tclOutWrite = _fdopen(_open_osfhandle((intptr_t)hTclOutWritePipe, _O_TEXT), "w");
}

TclPipe::~TclPipe() {
    fclose(tclInRead);
    fclose(tclInWrite);
    fclose(tclOutRead);
    fclose(tclOutWrite);
}

pTclPipes TclPipe::getTclPipes() {
    return new tclPipes { tclInRead, tclInWrite, tclOutRead, tclOutWrite };
}
