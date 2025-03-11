// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef TCLPIPE_H
#define TCLPIPE_H

#include <cstdio>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>

struct tclPipes {
    HANDLE hTclInReadPipe;
    FILE *tclInWritePipe;
    FILE *tclOutReadPipe;
    HANDLE hTclOutWritePipe;
};

typedef tclPipes *pTclPipes;

class TclPipe {
public:
    TclPipe();
    ~TclPipe();
    TclPipe(const TclPipe &) = delete;
    TclPipe &operator=(const TclPipe &) = delete;

    pTclPipes getTclPipes();

private:
    HANDLE hTclInReadPipe;
    HANDLE hTclInWritePipe;
    HANDLE hTclOutReadPipe;
    HANDLE hTclOutWritePipe;

    FILE *tclInWritePipe;
    FILE *tclOutReadPipe;
};

#endif // TCLPIPE_H
