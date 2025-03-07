// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "../src/function.h"
#include <sstream>
#include <iostream>

int main(int argc, char *argv[]) {
    std::ostringstream oss;
    Function func(oss);

    std::vector<std::string> args = { "1234" };
    func.BiasSet(args);
    std::string ret = oss.str();

    std::cout << oss.str() << std::endl;
}
