#include "command.h"
#include "macro.h"
#include "function.h"

Command::Command(Function &function) : m_function(function) {
    AddCommands;
}
