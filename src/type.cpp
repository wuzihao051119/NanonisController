// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "type.h"

std::ostream &operator<<(std::ostream &os, const nano_string &arg) {
    return os << arg.value;
}

std::ostream &operator<<(std::ostream &os, const nano_unsigned_int16 &arg) {
    return os << static_cast<unsigned char>(arg.value >> 8)
              << static_cast<unsigned char>(arg.value);
}

std::ostream &operator<<(std::ostream &os, const nano_int &arg) {
    return os << static_cast<unsigned char>(arg.value >> 24) 
              << static_cast<unsigned char>(arg.value >> 16)
              << static_cast<unsigned char>(arg.value >> 8)
              << static_cast<unsigned char>(arg.value);
}

std::ostream &operator<<(std::ostream &os, const nano_unsigned_int32 &arg) {
    return os << static_cast<unsigned char>(arg.value >> 24) 
              << static_cast<unsigned char>(arg.value >> 16)
              << static_cast<unsigned char>(arg.value >> 8)
              << static_cast<unsigned char>(arg.value);
}

std::ostream &operator<<(std::ostream &os, const nano_unsigned_int64 &arg) {
    return os << static_cast<unsigned char>(arg.value >> 56) 
              << static_cast<unsigned char>(arg.value >> 48)
              << static_cast<unsigned char>(arg.value >> 40)
              << static_cast<unsigned char>(arg.value >> 32)
              << static_cast<unsigned char>(arg.value >> 24) 
              << static_cast<unsigned char>(arg.value >> 16)
              << static_cast<unsigned char>(arg.value >> 8)
              << static_cast<unsigned char>(arg.value);
}

std::ostream &operator<<(std::ostream &os, const nano_float32 &arg) {
    return os << *reinterpret_cast<const nano_unsigned_int32 *>(&arg);
}

std::ostream &operator<<(std::ostream &os, const nano_float64 &arg) {
    return os << *reinterpret_cast<const nano_unsigned_int64 *>(&arg);
}

std::ostream &operator<<(std::ostream &os, const nano_1D_array_string &arg) {
    return appendArrayInternal(os, arg);
}

std::ostream &operator<<(std::ostream &os, const nano_1D_array_int &arg) {
    return appendArrayInternal(os, arg);
}

std::ostream &operator<<(std::ostream &os, const nano_1D_array_unsigned_int8 &arg) {
    return appendArrayInternal(os, arg);
}

std::ostream &operator<<(std::ostream &os, const nano_1D_array_unsigned_int32 &arg) {
    return appendArrayInternal(os, arg);
}

std::ostream &operator<<(std::ostream &os, const nano_1D_array_float32 &arg) {
    return appendArrayInternal(os, arg);
}

std::ostream &operator<<(std::ostream &os, const nano_1D_array_float64 &arg) {
    return appendArrayInternal(os, arg);
}

std::ostream &operator<<(std::ostream &os, const nano_2D_array_float32 &arg) {
    return append2DArrayInternal(os, arg);
}
