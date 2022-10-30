#include "dummy.h"



int dummy::dummyInt(const std::string& str) {
    return mFoo.fooInt(str);
}

void dummy::dummyStr(std::string& str) {
    mFoo.fooStr(str);
}

void dummy::dummyThrow() {
    mFoo.fooThrow();
}

void dummy::dummycallbackMethod(std::function<void(void)> callback) {
    mFoo.callbackMethod(callback);
}