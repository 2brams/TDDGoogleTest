#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <string>
#include "foo_if.h"


class dummy
{
    
public:
    dummy(fooIf& f): mFoo(f) {}
    ~dummy() {}

    int dummyInt(const std::string& str);
    fooIf& mFoo;
};

#endif