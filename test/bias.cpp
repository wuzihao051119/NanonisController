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
