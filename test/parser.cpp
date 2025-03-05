#include <sstream>
#include "../src/parser.h"

int main(int argc, char *argv[]) {
    std::ostringstream oss;
    appendArgument(oss, "123");
    std::string str1 = oss.str();
    oss.str("");
    appendArgument(oss, 1);
    std::string str2 = oss.str();
    oss.str("");
    nano_1D_array_float64 container1 = { 0.000000005, -0.000000005 };
    appendArgument(oss, container1);
    std::string str3 = oss.str();
    oss.str("");
    return 0;
}
