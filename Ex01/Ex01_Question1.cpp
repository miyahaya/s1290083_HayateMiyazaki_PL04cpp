#include <iostream>

bool isPrime(unsigned int x) {
    if (x < 2)
        return false;

    for (unsigned int i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return false;
    }

    return true;
}

int main() {
    // Test cases
    unsigned int testCases[] = {2, 3, 5, 7, 10, 13, 17, 20, 23, 29, 31};

    for (unsigned int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); ++i) {
        unsigned int num = testCases[i];
        bool result = isPrime(num);
        std::cout << num << " is " << (result ? "prime" : "not prime") << std::endl;
    }

    return 0;
}