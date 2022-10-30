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

TEST_F(testFixtureDummy, dummyStr)
{
    std::string str {"tata"};
    std::string resultStr {"exampleStr"};
    EXPECT_CALL(mFoo, fooStr(testing::_)).WillOnce(testing::SetArgReferee<0>(resultStr));
    mTestDummy->dummyStr(str);
    ASSERT_EQ(str, resultStr);
}

ACTION(throwError) {
    throw std::runtime_error("ERROR TEST");
}

void throwFuntion() {
    std::cout << "ERROR!\n";
    throw std::runtime_error("ERROR_TEST");
}

TEST_F(testFixtureDummy, dummyThrow)
{
    EXPECT_CALL(mFoo, fooThrow()).WillOnce(testing::Invoke(throwFuntion));
    ASSERT_THROW(mTestDummy->dummyThrow(), std::runtime_error);
}

TEST_F(testFixtureDummy, dummyCallback)
{
    testing::MockFunction<void(void)> testFunc;
    EXPECT_CALL(mFoo, callbackMethod(testing::_)).Times(1).
    WillOnce(testing::InvokeArgument<0>());
    EXPECT_CALL(testFunc, Call());
    mTestDummy->dummycallbackMethod(testFunc.AsStdFunction());
}
