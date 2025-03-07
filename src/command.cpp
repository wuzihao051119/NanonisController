// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "command.h"
#include "macro.h"
#include "function.h"

Command::Command(Function &function) : m_function(function) {
    AddCommands;
}
