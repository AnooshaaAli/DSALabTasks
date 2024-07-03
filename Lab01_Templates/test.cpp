#include "main.h"

/*  *********************Task-1 Test Cases*********************/
TEST(RemoveDupsTest, RemoveDupsIntArray) {
    int input[] = { 21, 32, 22, 33, 22 };
    int expected[] = { 21, 32, 22, 33 };

    size_t newSize = RemoveDups(input);

    ASSERT_EQ(newSize, sizeof(expected) / sizeof(expected[0]));
    ASSERT_TRUE(std::equal(input, input + newSize, expected));
}

TEST(RemoveDupsTest, RemoveDupsStringArray) {
    std::string input[] = { "sara", "mary", "larry", "sara" };
    std::string expected[] = { "sara", "mary", "larry" };

    size_t newSize = RemoveDups(input);

    ASSERT_EQ(newSize, sizeof(expected) / sizeof(expected[0]));
    ASSERT_TRUE(std::equal(input, input + newSize, expected));
}

/*  *********************Task-2 Test Cases*********************/
TEST(RotateTest, IntArrayRotation) {
    int strs[] = { 1, 2, 3, 4, 5, 6, 7 };
    int k = 2;
    Rotate(strs, k);

    int expected[] = { 3, 4, 5, 6, 7, 1, 2 };
    for (size_t i = 0; i < sizeof(strs) / sizeof(strs[0]); ++i) {
        ASSERT_EQ(strs[i], expected[i]);
    }
}

TEST(RotateTest, StringArrayRotation) {
    std::string strs[] = { "apple", "banana", "cherry", "date" };
    int k = 2;
    Rotate(strs, k);

    std::string expected[] = { "cherry", "date", "apple", "banana" };
    for (size_t i = 0; i < sizeof(strs) / sizeof(strs[0]); ++i) {
        ASSERT_EQ(strs[i], expected[i]);
    }
}

/*  *********************Task-3 Test Cases*********************/

TEST(ContainerTest, InsertInt) {
    Container<int> intContainer(5);
    intContainer.insert(10);
    intContainer.insert(20);

    EXPECT_TRUE(intContainer.search(10));
    EXPECT_TRUE(intContainer.search(20));
    EXPECT_FALSE(intContainer.search(30));
}

TEST(ContainerTest, InsertFloat) {
    Container<float> floatContainer(5);
    floatContainer.insert(3.14f);
    floatContainer.insert(2.718f);

    EXPECT_TRUE(floatContainer.search(3.14f));
    EXPECT_TRUE(floatContainer.search(2.718f));
    EXPECT_FALSE(floatContainer.search(1.0f));
}

TEST(ContainerTest, InsertString) {
    Container<std::string> stringContainer(5);
    stringContainer.insert("Hello");
    stringContainer.insert("World");

    EXPECT_TRUE(stringContainer.search("Hello"));
    EXPECT_TRUE(stringContainer.search("World"));
    EXPECT_FALSE(stringContainer.search("Goodbye"));
}

TEST(ContainerTest, RemoveInt) {
    Container<int> intContainer(5);
    intContainer.insert(10);
    intContainer.insert(20);
    intContainer.remove(10);

    EXPECT_FALSE(intContainer.search(10));
    EXPECT_TRUE(intContainer.search(20));
}

TEST(ContainerTest, RemoveFloat) {
    Container<float> floatContainer(5);
    floatContainer.insert(3.14f);
    floatContainer.insert(2.718f);
    floatContainer.remove(2.718f);

    EXPECT_TRUE(floatContainer.search(3.14f));
    EXPECT_FALSE(floatContainer.search(2.718f));
}

TEST(ContainerTest, RemoveString) {
    Container<std::string> stringContainer(5);
    stringContainer.insert("Hello");
    stringContainer.insert("World");
    stringContainer.remove("Hello");

    EXPECT_FALSE(stringContainer.search("Hello"));
    EXPECT_TRUE(stringContainer.search("World"));
}

/*  *********************Task-4 Test Cases*********************/


TEST(FindTargetIndicesTest, IntDataType) {
    int student_scores[] = { 10, 7, 0, 7 };
    int target_score = 14;
    auto result = findTargetIndices(student_scores, target_score);
    ASSERT_EQ(result, std::make_pair(1, 3));
}

TEST(FindTargetIndicesTest, DoubleDataType) {
    double student_scores[] = { 3.0, 2.0, 4.0 };
    double target_score = 6.0;
    auto result = findTargetIndices(student_scores, target_score);
    ASSERT_EQ(result, std::make_pair(1, 2));
}

TEST(FindTargetIndicesTest, FloatDataType) {
    float student_scores[] = { 1.5f, 2.5f, 3.0f };
    float target_score = 4.5f;
    auto result = findTargetIndices(student_scores, target_score);
    ASSERT_EQ(result, std::make_pair(0, 2));
}

