// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef FORMAT_H
#define FORMAT_H

#include "type.h"
#include "macro.h"

template <typename T, typename = void>
struct convertTo {
    const T &operator()(const std::string &str) {
        return str;
    }
};

template <>
struct convertTo<nano_string> {
    const nano_string &operator()(const std::string &str) {
        return nano_string(str);
    }
};

template <>
struct convertTo<nano_int> {
    const nano_int &operator()(const std::string &str) {
        return nano_int(std::stoi(str));
    }
};

template <>
struct convertTo<nano_unsigned_int16> {
    const nano_unsigned_int16 &operator()(const std::string &str) {
        return nano_unsigned_int16(std::stoi(str));
    }
};

template <>
struct convertTo<nano_unsigned_int32> {
    const nano_unsigned_int32 &operator()(const std::string &str) {
        return nano_unsigned_int32(std::stoi(str));
    }
};

template <>
struct convertTo<nano_float32> {
    const nano_float32 &operator()(const std::string &str) {
        return nano_float32(std::stof(str));
    }
};

template <>
struct convertTo<nano_float64> {
    const nano_float64 &operator()(const std::string &str) {
        return nano_float64(std::stod(str));
    }
};

template <typename T>
struct convertTo<T, std::enable_if_t<
    std::is_same_v<T, nano_1D_array_string> ||
    std::is_same_v<T, nano_1D_array_int> ||
    std::is_same_v<T, nano_1D_array_unsigned_int8> ||
    std::is_same_v<T, nano_1D_array_unsigned_int32> ||
    std::is_same_v<T, nano_1D_array_float32> ||
    std::is_same_v<T, nano_1D_array_float64> ||
    std::is_same_v<T, nano_2D_array_float32>
>> {
    const T &operator()(const std::string &str) {
        return T();
    }
};

template <typename T, typename ...Ts>
void appendArgs(std::ostream &os, std::vector<std::string> &args) {
    os << convertTo<T>()(args.front());
    std::begin(args)++;
    appendArgs<Ts...>(os, args);
}

template <>
inline void appendArgs<void>(std::ostream &os, std::vector<std::string> &args) {
    return;
}

#endif // FORMAT_H
