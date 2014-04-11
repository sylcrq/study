#include "gtest/gtest.h"

//assertions
//success, nonfatal failure, or fatal failure
//A test case contains one or many tests
//A test program can contain multiple test cases

//ASSERT_* versions generate fatal failures when they fail, and abort the current function
//EXPECT_* versions generate nonfatal failures, which don't abort the current function

TEST(test_case_name, basic) {
    ASSERT_TRUE(true);
    ASSERT_FALSE(false);

    EXPECT_TRUE(true);
    EXPECT_FALSE(false);
}

TEST(test_case_name, compare) {
    ASSERT_EQ(1, 1);  // expected == actual
    ASSERT_NE(1, 0);  // val1 != val2
    ASSERT_LT(1, 2);  // val1 < val2
    ASSERT_LE(2, 2);  // val1 <= val2
    ASSERT_GT(4, 1);  // val1 > val2
    ASSERT_GE(5, 5);  // val1 >= val2

    //EXPECT_*
}

//The assertions in this group compare two C strings. 
//If you want to compare two string objects, use EXPECT_EQ, EXPECT_NE, and etc instead
//A NULL pointer and an empty string are considered different.
//In particular, to assert that a C string is NULL, use ASSERT_STREQ(NULL, c_string)
TEST(test_case_name, string_compare) {
    ASSERT_STREQ("hello", "hello");  //the two C strings have the same content
    ASSERT_STRNE("hello", "world");  //the two C strings have different content
    ASSERT_STRCASEEQ("HeLlo", "hello");  //the two C strings have the same content, ignoring case
    ASSERT_STRCASENE("Hello", "World");  //the two C strings have different content, ignoring case

    //EXPECT_*
}

//Google Test groups the test results by test cases, so logically-related tests should be in the same test case;
//in other words, the first argument to their TEST() should be the same


//Test Fixture
//It allows you to reuse the same configuration of objects for several different tests.

//To create a fixture, just:
//1. Derive a class from ::testing::Test . Start its body with protected: or public: as we'll want to access fixture members from sub-classes.
//2. Inside the class, declare any objects you plan to use.
//3. If necessary, write a default constructor or SetUp() function to prepare the objects for each test. 
//4. If necessary, write a destructor or TearDown() function to release any resources you allocated in SetUp() .
//5. If needed, define subroutines for your tests to share.

class MagnetTest : public ::testing::Test
{
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

//Like TEST(), the first argument is the test case name, but for TEST_F() this must be the name of the test fixture class. 
//you must first define a test fixture class before using it in a TEST_F()

//Note that different tests in the same test case have different test fixture objects, 
//and Google Test always deletes a test fixture before it creates the next one.
TEST_F(MagnetTest, test_name) {
}

//Google Test is designed to be thread-safe. 
//The implementation is thread-safe on systems where the pthreads library is available. 
//It is currently unsafe to use Google Test assertions from two threads concurrently on other systems (e.g. Windows). 
