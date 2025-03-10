// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef COMMAND_H
#define COMMAND_H

#include <functional>
#include <iomanip>
#include <sstream>
#include <string>
#include <unordered_map>
#include "function.h"

class Command
{
public:
    Command() = delete;
    Command(const Command &) = delete;
    Command &operator=(const Command &) = delete;
    ~Command() = default;

    Command(Function &function, std::ostringstream &oss);
    Function &function() const { return m_function; }

    void invoke(const std::string &commandName, std::vector<std::string> &args);
    void makeHeader(const std::string &commandName, const int &bodySize);

private:
    std::unordered_map<std::string, std::function<void(std::vector<std::string> &)>> m_command;
    Function &m_function;
    bool m_sendResponseBack;
    std::ostringstream &m_oss;
};

#endif // COMMAND_H
