#include <sstream>
#include "../src/format.h"

int main(int argc, char *argv[]) {
    std::ostringstream oss;
    appendSingleType(oss, "123");
    std::string str1 = oss.str();
    oss.str("");
    appendSingleType(oss, 1);
    std::string str2 = oss.str();
    oss.str("");
    nano_1D_array_float64 container1 = { 0.000000005, -0.000000005 };
    appendSingleType(oss, container1);
    std::string str3 = oss.str();
    oss.str("");
    return 0;
}
