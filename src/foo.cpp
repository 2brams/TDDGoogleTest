#include "foo.h"

int foo::fooInt(const std::string &str) {
    return str.size();
}

void foo::fooStr(std::string &str) {
    str = "exampleStr";
}