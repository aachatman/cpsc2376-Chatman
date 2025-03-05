#include "gtest/gtest.h"
#include "practice03.cpp"

TEST(MathUtilsTests, TestSumRange) {
    // Test normal range
    EXPECT_EQ(MathUtils::sumRange(1, 5), 15); // 1 + 2 + 3 + 4 + 5 = 15

    // Test edge case where start == end
    EXPECT_EQ(MathUtils::sumRange(5, 5), 5); // 5 should be the sum

    // Test range including negative values
    EXPECT_EQ(MathUtils::sumRange(-2, 2), 0); // -2 + -1 + 0 + 1 + 2 = 0
}

TEST(MathUtilsTests, TestContainsNegative) {
    // Test when list contains negative numbers
    std::vector<int> values = { 1, 2, -3, 4 };
    EXPECT_TRUE(MathUtils::containsNegative(values));

    // Test when list contains no negative numbers
    std::vector<int> positiveValues = { 1, 2, 3, 4 };
    EXPECT_FALSE(MathUtils::containsNegative(positiveValues));

    // Test when list is empty
    std::vector<int> emptyValues = {};
    EXPECT_FALSE(MathUtils::containsNegative(emptyValues));
}

TEST(MathUtilsTests, TestFindMax) {
    // Test normal case
    std::vector<int> values = { 3, -1, 5, 7 };
    EXPECT_EQ(MathUtils::findMax(values), 7);

    // Test all values are equal
    std::vector<int> equalValues = { 4, 4, 4 };
    EXPECT_EQ(MathUtils::findMax(equalValues), 4);

    // Test when list is empty, should throw an exception
    std::vector<int> emptyValues = {};
    EXPECT_THROW(MathUtils::findMax(emptyValues), std::invalid_argument);
}
