#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

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

    // Calculate sum using std::accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    // Calculate product using std::accumulate
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());

    std::cout << "Sum of all elements: " << sum << std::endl;
    std::cout << "Product of all elements: " << product << std::endl;

    return 0;
}