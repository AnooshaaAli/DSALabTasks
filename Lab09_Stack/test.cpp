#include "pch.h"
#include "main.h"
#include <string>


//***************** Q1 Test cases *****************
TEST(StackTest, PushPop) {
    Stack<int> stack1;
    stack1.push(42);
    stack1.push(43);
    stack1.push(44);
    stack1.print();
    EXPECT_EQ(stack1.peek(), 44);
    stack1.pop();
    EXPECT_FALSE(stack1.isEmpty());
    stack1.pop();
    stack1.pop();
    stack1.print();
    EXPECT_TRUE(stack1.isEmpty());
}

TEST(StackTest, Clear) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.clear();
    EXPECT_TRUE(stack.isEmpty());
}

TEST(StackTest, EmptyStack) {
    Stack<int> stack;
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_THROW(stack.pop(), std::runtime_error);
    EXPECT_THROW(stack.peek(), std::runtime_error);
}


//***************** Q2 Test cases *****************
TEST(RemoveKDigitsTest, Example1) {
    std::string num = "1432219";
    int k = 3;
    std::string actual = removeKDigits(num, k);
    EXPECT_EQ(actual, "1219");
}

TEST(RemoveKDigitsTest, Example2) {
    std::string num = "10200";
    int k = 1;
    EXPECT_EQ(removeKDigits(num, k), "200");
}

TEST(RemoveKDigitsTest, Example3) {
    std::string num = "10";
    int k = 2;
    EXPECT_EQ(removeKDigits(num, k), "0");
}

TEST(RemoveKDigitsTest, Example4) {
    std::string num = "12136";
    int k = 3;
    EXPECT_EQ(removeKDigits(num, k), "11");
}

TEST(RemoveKDigitsTest, Example5)
{
    std::string num = "9931014";
    int k = 4;
    EXPECT_EQ(removeKDigits(num, k), "14");
}

//***************** Q3 Test cases *****************
TEST(SimplifyPathTest, Test1)
{
    std::string path1 = "/home/";
    EXPECT_EQ(simplifyPath(path1), "/home");
}

TEST(SimplifyPathTest, Test2)
{
    std::string path2 = "/../";
    EXPECT_EQ(simplifyPath(path2), "/");
}

TEST(SimplifyPathTest, Test3)
{
    std::string path3 = "/home//foo/";
    EXPECT_EQ(simplifyPath(path3), "/home/foo");
}
