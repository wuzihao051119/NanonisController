#ifndef FORMAT_H
#define FORMAT_H

#include "type.h"
#include "macro.h"

template <typename T>
void appendSingleType(std::ostream &os, T arg) {
    os << arg;
}

template <>
inline void appendSingleType(std::ostream &os, nano_unsigned_int16 arg) {
    os << static_cast<unsigned char>(arg >> 8) << static_cast<unsigned char>(arg);
}

template <>
inline void appendSingleType(std::ostream &os, nano_int arg) {
    appendSingleType(os, static_cast<std::uint16_t>(arg >> 16));
    appendSingleType(os, static_cast<std::uint16_t>(arg));
}

template <>
inline void appendSingleType(std::ostream &os, nano_unsigned_int32 arg) {
    appendSingleType(os, static_cast<std::uint16_t>(arg >> 16));
    appendSingleType(os, static_cast<std::uint16_t>(arg));
}

template <>
inline void appendSingleType(std::ostream& os, std::uint64_t arg) {
    appendSingleType(os, static_cast<std::uint32_t>(arg >> 32));
    appendSingleType(os, static_cast<std::uint32_t>(arg));
}

template <>
inline void appendSingleType(std::ostream &os, nano_float32 arg) {
    appendSingleType(os, *reinterpret_cast<std::uint32_t *>(&arg));
}

template <>
inline void appendSingleType(std::ostream &os, nano_float64 arg) {
    appendSingleType(os, *reinterpret_cast<std::uint64_t *>(&arg));
}

template <typename T>
void appendSingleType(std::ostream &os, std::vector<T> &arg) {
    if (arg.empty())
        return;
    appendSingleType(os, arg.front());
    std::swap(*std::begin(arg), *(std::end(arg) - 1));
    arg.pop_back();
    appendSingleType(os, arg);
}

template <typename T, typename = void>
T convertTo(std::string &str) {
    return str;
}

template <>
inline nano_int convertTo(std::string &str) {
    return std::stoi(str);
}

template <>
inline nano_unsigned_int16 convertTo(std::string &str) {
    return static_cast<nano_unsigned_int16>(std::stoi(str));
}

template <>
inline nano_unsigned_int32 convertTo(std::string &str) {
    return static_cast<nano_unsigned_int32>(std::stoi(str));
}

template <>
inline nano_float32 convertTo(std::string &str) {
    return std::stof(str);
}

template <>
inline nano_float64 convertTo(std::string &str) {
    return std::stod(str);
}

template <typename T, typename ...Ts>
void appendArgs(std::ostream &os, std::vector<std::string> &args) {
    appendSingleType(os, convertTo<T>(args.front()));
    std::swap(*std::begin(args), *(std::end(args) - 1));
    args.pop_back();
    appendArgs<Ts...>(os, args);
}

template <>
inline void appendArgs<void>(std::ostream &os, std::vector<std::string> &args) {
    return;
}

#endif // FORMAT_H
