// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "command.h"
#include "macro.h"
#include "function.h"

Command::Command(Function &function, std::ostringstream &oss) : m_function(function), m_oss(oss), m_sendResponseBack(true) {
    AddCommands;
    AddDumpCommands;
}

void Command::invoke(const std::string &commandName, std::vector<std::string> &args) {
    m_oss.str("");

    m_command.at(commandName)(args);
    std::string body = m_oss.str();
    m_oss.str("");

    makeHeader(commandName, body.length());
    std::string header = m_oss.str();
    m_oss.str("");

    m_oss << header << body;
    
    emit socketSend(QByteArray(m_oss.str()));
}

void Command::makeHeader(const std::string &commandName, const int &bodySize) {
    nano_int size(bodySize);
    nano_unsigned_int16 sendResponseBack(m_sendResponseBack);
    nano_unsigned_int16 notUsed(0);
    m_oss << std::setfill('\0') << std::left << std::setw(32) << commandName << size << sendResponseBack << notUsed;
}

const std::string Command::dump(const std::string &response) {
    m_oss.str("");

    std::string commandName = response.substr(0, 32).c_str();
    int bodySize = std::stoi(convertFromHex<nano_unsigned_int32>()(response, 32));
    int notUsed = std::stoi(convertFromHex<nano_unsigned_int32>()(response, 36));

    size_t offset = 40;
    m_dumpCommand.at(commandName)(response, &offset);

    int errorStatus = std::stoi(convertFromHex<nano_unsigned_int32>()(response, offset));
    int errorDescriptionSize = std::stoi(convertFromHex<nano_unsigned_int32>()(response, offset + 4));
    std::string errorDescription = response.substr(offset + 8);

    m_oss << commandName << " " << bodySize << " " << errorStatus << " " << errorDescriptionSize << " " << errorDescription;

    return m_oss.str();
}
