// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef FUNCTION_H
#define FUNCTION_H

#include "format.h"
#include "macro.h"
#include "type.h"

class Function
{
public:
    Function() = delete;
    Function(const Function &) = delete;
    Function &operator=(const Function &) = delete;
    ~Function() = default;

    Function(std::ostream &os) : m_os(os) {}
    std::ostream &stream() const { return m_os; }

    AddWholeFunctions;

private:
    std::ostream &m_os;
};

#endif // FUNCTION_H
