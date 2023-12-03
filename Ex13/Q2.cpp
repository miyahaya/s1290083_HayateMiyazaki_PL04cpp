#include <iostream>
#include <vector>
#include <algorithm>

double compute_median(const std::vector<double>& numbers) {
    std::vector<double> sortedNumbers = numbers;
    std::size_t middleIndex = sortedNumbers.size() / 2;
    std::nth_element(sortedNumbers.begin(), sortedNumbers.begin() + middleIndex, sortedNumbers.end());
    double median = sortedNumbers[middleIndex];

    if (sortedNumbers.size() % 2 == 0) {
        std::nth_element(sortedNumbers.begin(), sortedNumbers.begin() + middleIndex + 1, sortedNumbers.end());
        median = (median + sortedNumbers[middleIndex + 1]) / 2.0;
    }

    return median;
}

std::vector<double> compute_k_closest(const std::vector<double>& numbers, int k) {
    double median = compute_median(numbers);

    auto compareDistance = [median](double a, double b) {
        return std::abs(a - median) < std::abs(b - median);
    };

    std::vector<double> closestNumbers = numbers;
    std::nth_element(closestNumbers.begin(), closestNumbers.begin() + k, closestNumbers.end(), compareDistance);

    closestNumbers.resize(k);

    return closestNumbers;
}

int main() {
    std::vector<double> numbers = {1.5, 2.3, 0.8, 4.2, 3.1};
    int k = 3;

    std::vector<double> closestNumbers = compute_k_closest(numbers, k);

    std::cout << "Closest Numbers to Median: ";
    for (double num : closestNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}