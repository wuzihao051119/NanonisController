// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef FORMAT_H
#define FORMAT_H

#include "type.h"
#include "macro.h"

template <typename T, typename = void>
struct convertToHex {
    const T &operator()(const std::string &str) {
        return str;
    }
};

template <>
struct convertToHex<nano_string> {
    const nano_string &operator()(const std::string &str) {
        return *new nano_string(str);
    }
};

template <>
struct convertToHex<nano_int> {
    const nano_int &operator()(const std::string &str) {
        return *new nano_int(std::stoi(str));
    }
};

template <>
struct convertToHex<nano_unsigned_int16> {
    const nano_unsigned_int16 &operator()(const std::string &str) {
        return *new nano_unsigned_int16(std::stoi(str));
    }
};

template <>
struct convertToHex<nano_unsigned_int32> {
    const nano_unsigned_int32 &operator()(const std::string &str) {
        return *new nano_unsigned_int32(std::stoi(str));
    }
};

template <>
struct convertToHex<nano_float32> {
    const nano_float32 &operator()(const std::string &str) {
        return *new nano_float32(std::stof(str));
    }
};

template <>
struct convertToHex<nano_float64> {
    const nano_float64 &operator()(const std::string &str) {
        return *new nano_float64(std::stod(str));
    }
};

template <typename T>
struct convertToHex<T, std::enable_if_t<
    std::is_same_v<T, nano_1D_array_string> ||
    std::is_same_v<T, nano_1D_array_int> ||
    std::is_same_v<T, nano_1D_array_unsigned_int8> ||
    std::is_same_v<T, nano_1D_array_unsigned_int32> ||
    std::is_same_v<T, nano_1D_array_float32> ||
    std::is_same_v<T, nano_1D_array_float64> ||
    std::is_same_v<T, nano_2D_array_float32>
>> {
    const T &operator()(const std::string &str) {
        return *new T();
    }
};

template <typename T, typename = void>
struct convertFromHex {
    const std::string operator()(const std::string &str, size_t offset) {
        return str.substr(offset);
    }
};

template <>
struct convertFromHex<nano_string> {
    const std::string operator()(const std::string &str, size_t offset) {
        return str.substr(offset);
    }
};

template <>
struct convertFromHex<nano_int> {
    const std::string operator()(const std::string &str, size_t offset) {
        std::string content = str.substr(offset, 4);
        std::reverse(content.begin(), content.end());
        return std::to_string(*reinterpret_cast<const int *>(content.c_str()));
    }
};

template <>
struct convertFromHex<nano_unsigned_int16> {
    const std::string operator()(const std::string &str, size_t offset) {
        std::string content = str.substr(offset, 2);
        std::reverse(content.begin(), content.end());
        return std::to_string(*reinterpret_cast<const uint16_t*>(content.c_str()));
    }
};

template <>
struct convertFromHex<nano_unsigned_int32> {
    const std::string operator()(const std::string &str, size_t offset) {
        std::string content = str.substr(offset, 4);
        std::reverse(content.begin(), content.end());
        return std::to_string(*reinterpret_cast<const uint32_t*>(content.c_str()));
    }
};

template <>
struct convertFromHex<nano_float32> {
    const std::string operator()(const std::string &str, size_t offset) {
        std::string content = str.substr(offset, 4);
        std::reverse(content.begin(), content.end());
        return std::to_string(*reinterpret_cast<const float*>(content.c_str()));
    }
};

template <>
struct convertFromHex<nano_float64> {
    const std::string operator()(const std::string &str, size_t offset) {
        std::string content = str.substr(offset, 8);
        std::reverse(content.begin(), content.end());
        return std::to_string(*reinterpret_cast<const double*>(content.c_str()));
    }
};

template <typename T>
struct convertFromHex<T, std::enable_if_t<
    std::is_same_v<T, nano_1D_array_string> ||
    std::is_same_v<T, nano_1D_array_int> ||
    std::is_same_v<T, nano_1D_array_unsigned_int8> ||
    std::is_same_v<T, nano_1D_array_unsigned_int32> ||
    std::is_same_v<T, nano_1D_array_float32> ||
    std::is_same_v<T, nano_1D_array_float64> ||
    std::is_same_v<T, nano_2D_array_float32>
>> {
    const std::string operator()(const std::string &str, size_t offset) {
        return str.substr(offset);
    }
};

template <typename T, typename ...Ts>
void appendArgs(std::ostream &os, std::vector<std::string> &args) {
    os << convertToHex<T>()(args.front());
    args.erase(args.begin());
    appendArgs<Ts...>(os, args);
}

template <>
inline void appendArgs<void>(std::ostream &os, std::vector<std::string> &args) {
    return;
}

template <typename T, typename ...Ts>
void appendDumps(std::ostream& os, const std::string &dumpBody, size_t *offset) {
    os << convertFromHex<T>()(dumpBody, *offset) << " ";
    *offset += sizeof(T);
    appendDumps<Ts...>(os, dumpBody, offset);
}

template <>
inline void appendDumps<void>(std::ostream& os, const std::string& dumpBody, size_t *offset) {
    return;
}

#endif // FORMAT_H
