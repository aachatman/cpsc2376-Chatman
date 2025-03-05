# Identified Bugs and Fixes

## Bug 1: sumRange (Off-by-one error)
- **Issue**: The loop in the `sumRange` function uses `i < end`, which excludes the `end` value from the sum.
- **Fix**: Change the loop condition to `i <= end`.

## Bug 2: containsNegative (Wrong loop condition and incorrect check)
- **Issue 1**: The loop runs to `i <= numbers.size()`, which accesses an out-of-bounds index.
- **Issue 2**: The check `if (numbers[i] > 0)` is incorrect; it should check for negative numbers, i.e., `if (numbers[i] < 0)`.
- **Fixes**: 
  - Change the loop condition to `i < numbers.size()`.
  - Change the condition to `if (numbers[i] < 0)`.

## Bug 3: findMax (Empty list handling, off-by-one error, incorrect max comparison)
- **Issue 1**: The function returns 0 when the list is empty, but this is incorrect behavior. It should throw an exception.
- **Issue 2**: The loop condition is `i <= numbers.size()`, which leads to out-of-bounds access.
- **Issue 3**: The condition `if (numbers[i] >= maxVal)` is incorrect. It should be `if (numbers[i] > maxVal)` to find the correct maximum.
- **Fixes**:
  - Throw an `std::invalid_argument` exception for empty lists.
  - Change the loop condition to `i < numbers.size()`.
  - Change the condition to `if (numbers[i] > maxVal)`.
