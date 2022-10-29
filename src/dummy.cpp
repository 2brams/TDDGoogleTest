#include "dummy.h"



int dummy::dummyInt(const std::string& str) {
    return mFoo.fooInt(str);
}

void dummy::dummyStr(std::string& str) {
    mFoo.fooStr(str);
}