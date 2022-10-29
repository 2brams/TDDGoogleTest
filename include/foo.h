#ifndef FOO_HPP
#define FOO_HPP

#include "foo_if.h"

class foo : public fooIf
{
public:
    foo() {}
    ~foo() {}

    int fooInt(const std::string &str);
    void fooStr(std::string &str);
};

#endif