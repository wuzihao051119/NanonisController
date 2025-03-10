// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include <sstream>
#include "../../src/format.h"

int main(int argc, char *argv[]) {
    std::ostringstream oss;
    oss << nano_string("123");
    std::string str1 = oss.str();
    oss.str("");
    oss << nano_int(1);
    std::string str2 = oss.str();
    oss.str("");
    nano_1D_array_float64 container1;
    container1.value.emplace_back(0.000000005);
    container1.value.emplace_back(-0.000000005);
    oss << container1;
    std::string str3 = oss.str();
    oss.str("");
    return 0;
}
