#ifndef PARSER_H
#define PARSER_H

#include "type.h"

template <typename T>
void appendArgument(std::ostream &os, T arg) {
    os << arg;
}

template <>
void appendArgument(std::ostream &os, nano_unsigned_int16 arg) {
    os << static_cast<unsigned char>(arg >> 8) << static_cast<unsigned char>(arg);
}

template <>
void appendArgument(std::ostream &os, nano_int arg) {
    appendArgument(os, static_cast<std::uint16_t>(arg >> 16));
    appendArgument(os, static_cast<std::uint16_t>(arg));
}

template <>
void appendArgument(std::ostream &os, nano_unsigned_int32 arg) {
    appendArgument(os, static_cast<std::uint16_t>(arg >> 16));
    appendArgument(os, static_cast<std::uint16_t>(arg));
}

template <>
void appendArgument(std::ostream& os, std::uint64_t arg) {
    appendArgument(os, static_cast<std::uint32_t>(arg >> 32));
    appendArgument(os, static_cast<std::uint32_t>(arg));
}

template <>
void appendArgument(std::ostream &os, nano_float32 arg) {
    appendArgument(os, *reinterpret_cast<std::uint32_t *>(&arg));
}

template <>
void appendArgument(std::ostream &os, nano_float64 arg) {
    appendArgument(os, *reinterpret_cast<std::uint64_t *>(&arg));
}

template <typename T>
void appendArgument(std::ostream &os, std::vector<T> &arg) {
    if (arg.empty())
        return;
    appendArgument(os, arg[0]);
    std::swap(*std::begin(arg), *(std::end(arg) - 1));
    arg.pop_back();
    appendArgument(os, arg);
}

//template <typename ...T>
//char* parseToBody(T... args) {
//
//}

#endif // PARSER_H
