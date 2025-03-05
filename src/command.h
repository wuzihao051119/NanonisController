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
    // using argType = std::variant<
    //     nano_string,
    //     nano_int,
    //     nano_unsigned_int16,
    //     nano_unsigned_int32,
    //     nano_float32,
    //     nano_float64,
    //     nano_1D_array_string,
    //     nano_1D_array_int,
    //     nano_1D_array_unsigned_int32,
    //     nano_1D_array_unsigned_int8,
    //     nano_1D_array_float32,
    //     nano_1D_array_float64,
    //     nano_2D_array_float32
    // >;

    std::unordered_map<std::string, std::function<std::string(std::vector<std::string>)>> command;
};

#endif // COMMAND_H
