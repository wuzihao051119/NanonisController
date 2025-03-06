#ifndef COMMAND_H
#define COMMAND_H

#include <functional>
#include <string>
#include <unordered_map>

class Command
{
public:
    Command();
    ~Command();

private:
    std::unordered_map<std::string, std::function<std::string &(std::vector<std::string> &)>> command;
};

#endif // COMMAND_H
