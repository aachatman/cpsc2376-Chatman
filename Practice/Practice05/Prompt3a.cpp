#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <algorithm> // For std::for_each

int main() {
    std::vector<int> numbers;
    int num, n;

    std::cout << "Enter the number of integers you want to input: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers: \n";
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        numbers.push_back(num);
    }

    // Use std::for_each and lambda to print each element squared
    std::cout << "Squares of the elements: \n";
    std::for_each(numbers.begin(), numbers.end(), [](int x) {
        std::cout << x * x << " ";
    });

    std::cout << "\n";

    // Use std::accumulate with a lambda to sum the squared values
    int sum_of_squares = std::accumulate(numbers.begin(), numbers.end(), 0, [](int acc, int x) {
        return acc + x * x; // Sum up the squared values
    });

    std::cout << "Sum of squares of all elements: " << sum_of_squares << std::endl;

    return 0;
}