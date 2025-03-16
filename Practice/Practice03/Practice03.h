// Practice03.h
#pragma once

#include <vector>
#include <climits> // For INT_MIN

class MathUtils {
public:
    static int sumRange(int start, int end);
    static bool containsNegative(const std::vector<int>& numbers);
    static int findMax(const std::vector<int>& numbers);
};
