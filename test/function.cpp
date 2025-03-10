// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include <sstream>
#include <vector>
#include "../src/function.h"

int main(int argc, char *argv) {
    std::ostringstream oss;
    Function f(oss);

    // Bias.Set
    std::vector<std::string> container1 = { "0.000000005" };
    f.BiasSet(container1);
    std::string body1 = oss.str();
    oss.str("");

    // FolMe.XYPosSet
    std::vector<std::string> container2 = { "0.00000001", "0.000000015", "1" };
    f.FolMeXYPosSet(container2);
    std::string body2 = oss.str();
    oss.str("");

    return 0;
}
