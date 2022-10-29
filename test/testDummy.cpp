#include <iostream>
#include <gtest/gtest.h>
#include "dummy.h"
#include "mock_foo.h"
#include <memory>


class testFixtureDummy : public testing::Test
{
public:
    testFixtureDummy() {
        mTestDummy = std::make_unique<dummy>(mFoo);
    }
    ~testFixtureDummy() {
    }

    void SetUp()
    {
    }

    void TearDown()
    {
    }
    mockFoo mFoo;
    std::unique_ptr<dummy> mTestDummy;

};

TEST_F(testFixtureDummy, dummyInt)
{
    std::string str {"tata"};
    EXPECT_CALL(mFoo, fooInt(str)).Times(1).WillOnce(testing::Return(str.size()));
    int result = mTestDummy->dummyInt(str);
    ASSERT_EQ(result, str.size());
}
