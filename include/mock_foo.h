#include "foo_if.h"
#include <gmock/gmock.h>

class mockFoo : public fooIf
{
public:
    mockFoo() {}
    ~mockFoo() {}
    MOCK_METHOD(int, fooInt, (const std::string &str), (override));
};