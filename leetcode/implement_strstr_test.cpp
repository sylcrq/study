#include "gtest/gtest.h"

char *strStr(char *haystack, char *needle);

TEST(StrstrTestCase, InvaidInput)
{
    char* haystack = "hello world";
    char* needle = "world";

    EXPECT_EQ(NULL, strStr(NULL, NULL));
    EXPECT_EQ(NULL, strStr(NULL, needle));
    EXPECT_EQ(haystack, strStr(haystack, NULL));
    EXPECT_EQ(NULL, strStr("haha", "hahaha"));
}

TEST(StrstrTestCase, Normal)
{
    char* haystack = "hello world";
    char* haystack2 = "hello world !";
    char* needle = "world";

    EXPECT_EQ(haystack+6, strStr(haystack, needle));
    EXPECT_EQ(haystack2+6, strStr(haystack2, needle));
}
