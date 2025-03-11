// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include <iostream>
#include <Windows.h>

DWORD writePipe(HANDLE hWritePipe) {
    PCSTR chBuf = "hello";
    DWORD dwWritten;
    WriteFile(hWritePipe, chBuf, sizeof(chBuf), &dwWritten, NULL);
    return dwWritten;
}

DWORD readPipe(HANDLE hReadPipe, PCHAR chBuf, DWORD length) {
    DWORD dwRead;
    ReadFile(hReadPipe, chBuf, sizeof(chBuf), &dwRead, NULL);
    return dwRead;
}

int main() {
    HANDLE hReadPipe, hWritePipe;
    BOOL ret = CreatePipe(&hReadPipe, &hWritePipe, NULL, 0);
    if (ret == 0) {
        std::cout << GetLastError();
    }

    CHAR chBuf[10];

    writePipe(hWritePipe);
    readPipe(hReadPipe, chBuf, sizeof(chBuf));

    std::cout << chBuf << std::endl;

    return 0;
}
