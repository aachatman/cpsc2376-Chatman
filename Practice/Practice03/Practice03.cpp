// Practice03.cpp
#include "Practice03.h"
#include <iostream>

int MathUtils::sumRange(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {  // Fixed: inclusive of 'end'
        sum += i;
    }
    return sum;
}

bool MathUtils::containsNegative(const std::vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers.at(i) < 0) {  // Fixed: check for negative values
            return true;
        }
    }
    return false;
}

int MathUtils::findMax(const std::vector<int>& numbers) {
    if (numbers.empty()) return INT_MIN;  // Fixed: return INT_MIN for empty list
    int maxVal = numbers.at(0);
    for (size_t i = 1; i < numbers.size(); i++) {  // Fixed: loop should end at numbers.size() - 1
        if (numbers.at(i) > maxVal) {  // Fixed: max should be strictly greater
            maxVal = numbers.at(i);
        }
    }
    return maxVal;
}
