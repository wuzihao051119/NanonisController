// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef TYPE_H
#define TYPE_H

#include <algorithm>
#include <ostream>
#include <string>
#include <vector>

struct nano_string {
    std::string value;
    friend std::ostream &operator<<(std::ostream &os, const nano_string &arg);
};

struct nano_int {
    std::int32_t value;
    friend std::ostream &operator<<(std::ostream &os, const nano_int &arg);
};

struct nano_unsigned_int16 {
    std::uint16_t value;
    friend std::ostream &operator<<(std::ostream &os, const nano_unsigned_int16 &arg);
};

struct nano_unsigned_int32 {
    std::uint32_t value;
    friend std::ostream &operator<<(std::ostream &os, const nano_unsigned_int32 &arg);
};

struct nano_unsigned_int64 {
    std::uint64_t value;
    friend std::ostream &operator<<(std::ostream &os, const nano_unsigned_int64 &arg);
};

struct nano_float32 {
    float value;
    friend std::ostream &operator<<(std::ostream &os, const nano_float32 &arg);
};

struct nano_float64 {
    double value;
    friend std::ostream &operator<<(std::ostream &os, const nano_float64 &arg);
};

struct nano_1D_array_string {
    std::vector<nano_string> value;
    friend std::ostream &operator<<(std::ostream &os, const nano_1D_array_string &arg);
};

struct nano_1D_array_int {
    std::vector<nano_int> value;
    friend std::ostream &operator<<(std::ostream &os, const nano_1D_array_int &arg);
};

struct nano_1D_array_unsigned_int8 {
    std::vector<std::uint8_t> value;
    friend std::ostream &operator<<(std::ostream &os, const nano_1D_array_unsigned_int8 &arg);
};

struct nano_1D_array_unsigned_int32 {
    std::vector<nano_unsigned_int32> value;
    friend std::ostream &operator<<(std::ostream &os, const nano_1D_array_unsigned_int32 &arg);
};

struct nano_1D_array_float32 {
    std::vector<nano_float32> value;
    friend std::ostream &operator<<(std::ostream &os, const nano_1D_array_float32 &arg);
};

struct nano_1D_array_float64 {
    std::vector<nano_float64> value;
    friend std::ostream &operator<<(std::ostream &os, const nano_1D_array_float64 &arg);
};

struct nano_2D_array_float32 {
    std::vector<std::vector<nano_float32>> value;
    friend std::ostream &operator<<(std::ostream &os, const nano_2D_array_float32 &arg);
};

template <typename T, typename = std::enable_if_t<
    std::is_same_v<T, nano_1D_array_int> ||
    std::is_same_v<T, nano_1D_array_string> ||
    std::is_same_v<T, nano_1D_array_unsigned_int8> ||
    std::is_same_v<T, nano_1D_array_unsigned_int32> ||
    std::is_same_v<T, nano_1D_array_float32> ||
    std::is_same_v<T, nano_1D_array_float64>
>>
std::ostream &appendArrayInternal(std::ostream &os, const T &arg) {
    std::for_each(arg.value.begin(), arg.value.end(), [&os](const decltype(arg.value)::value_type &item) { os << item; });
    return os;
}

template <typename T, typename = std::enable_if_t<std::is_same_v<T, nano_2D_array_float32>>>
std::ostream &append2DArrayInternal(std::ostream &os, const T &arg) {
    return os;
}

#endif // TYPE_H
