#include <iostream>
#include <gtest/gtest.h>

using namespace std;
// g++ example.cpp googletest/build/lib/libgtest.a googletest/build/lib/libgtest_main.a -lpthread -I googletest/googletest/include/

class example
{
public:
    example() {}
    ~example() {}
    int foo(){
        return 1;
    }
};


class testFixture : public testing::Test
{
public:
    testFixture() {
        std::cout << "const" << std::endl;
        ex = new example();
    }
    ~testFixture() {
        std::cout << "dest" << std::endl;
    }

    void SetUp()
    {
        std::cout << "set" << std::endl;
    }

    void TearDown()
    {
        std::cout << "down" << std::endl;
    }

    example* ex;

};


TEST_F(testFixture, test1)
{
    ASSERT_EQ(1,ex->foo());
}

TEST_F(testFixture, test2)
{
    ASSERT_NE(0,ex->foo());
}

// int main(int argc, char ** argv) 
// {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();

// }