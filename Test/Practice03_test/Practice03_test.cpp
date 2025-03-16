#include "pch.h"  // Precompiled header (generated automatically by Visual Studio)
#include "CppUnitTest.h"  // Include for the Unit Test Framework
#include "Practice03.h"  // Include your header file for MathUtils

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Practice03Test
{
    TEST_CLASS(Practice03Test)
    {
    public:

        TEST_METHOD(TestSumRange)
        {
            // Test sumRange method
            Assert::AreEqual(MathUtils::sumRange(1, 5), 15);    // 1 + 2 + 3 + 4 + 5 = 15
            Assert::AreEqual(MathUtils::sumRange(5, 5), 5);      // Only 5, sum is 5
            Assert::AreEqual(MathUtils::sumRange(-2, 2), 0);     // -2 + -1 + 0 + 1 + 2 = 0
        }

        TEST_METHOD(TestContainsNegative)
        {
            // Test containsNegative method
            Assert::IsTrue(MathUtils::containsNegative({3, -1, 5, 7}));   // Contains negative
            Assert::IsFalse(MathUtils::containsNegative({3, 1, 5, 7}));   // No negatives
            Assert::IsFalse(MathUtils::containsNegative({}));              // Empty vector, no negatives
        }

        TEST_METHOD(TestFindMax)
        {
            // Test findMax method
            Assert::AreEqual(MathUtils::findMax({3, -1, 5, 7}), 7);    // Max value is 7
            Assert::AreEqual(MathUtils::findMax({5}), 5);              // Only one element, so 5
            Assert::AreEqual(MathUtils::findMax({5, 5, 5, 5}), 5);     // All elements are the same, so 5
            Assert::AreEqual(MathUtils::findMax({}), INT_MIN);         // Empty vector, return INT_MIN
        }
    };
}
