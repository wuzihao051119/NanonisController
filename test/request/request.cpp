// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "../../src/command.h"

int main(int argc, char *argv) {
    std::ostringstream oss;
    Function *f = new Function(oss);
    Command *c = new Command(*f, oss);

    std::vector<std::string> args = { "0.000000005" };
    c->invoke("Bias.Set", args);
    std::string request = oss.str();
    oss.str("");

    return 0;
}
