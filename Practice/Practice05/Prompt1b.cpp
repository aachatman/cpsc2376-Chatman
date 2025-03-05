#include <iostream>
#include <vector>

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

    std::cout << "The numbers in reverse order are: \n";

    // Accessing vector elements in reverse order using regular index-based for loop
    for (int i = n - 1; i >= 0; --i) {
        std::cout << numbers.at(i) << " ";
    }

    std::cout << std::endl;
    return 0;
}