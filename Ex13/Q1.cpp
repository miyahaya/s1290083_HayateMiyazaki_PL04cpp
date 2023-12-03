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

int main() {
    std::vector<double> numbers = {1.5, 2.3, 0.8, 4.2, 3.1};
    double median = compute_median(numbers);
    std::cout << "Median: " << median << std::endl;

    return 0;
}