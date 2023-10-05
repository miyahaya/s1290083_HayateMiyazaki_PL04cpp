#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// determine whether a number is prime or not
bool isPrime(int n){
    if(n == 2) return true; //Returns true if n is 2
    if(n%2 == 0 || n < 1)return false; //Returns faules if even or less than 1

    int bitPsition =63 -  ((n + 1)/2 - 1) % 64; //Substitute the number of right shift operations
    // Calculate and assign which of P0 to P7 is to be used
    int pNumber;
    for(int i = 0; i < 8; i++){
        if(n < 128) {
            pNumber = i;
            break;
        }
        else n = n - 128;
    }

    unsigned long long int P[] = {0b0111011011010011001011010010011001011001010010001011011010000001ULL,
    0b0100110000110010010100100110000110110000010000010110100110000100ULL,
    0b1001001100101100001000000101101000000100100001101001000100100101ULL,
    0b0010001010001000011000011001010010001011010000010001010001010010ULL,
    0b0000110000000010010000100100110010000100100110010010110000010000ULL,
    0b1101001001100000101001000100001000100001000100100101000100101000ULL,
    0b1010000001000010000011000011011000010000001011010000001011010000ULL,
    0b0000010100010000100010100100100000010100100100010010000010100110ULL};
    
    int shiftedValue = P[pNumber] >> bitPsition; //Right shift operation

    return (shiftedValue & 1) != 0; //return true or faulse.
}

int main() {
    // Randomize test cases
    const int SIZE = 100;
    int testCases[SIZE];

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Stores a random integer in an array
    for (int i = 0; i < SIZE; ++i) {
        testCases[i] = std::rand() % 1025; // 0から1024までの乱数を生成
    }

    std::sort(testCases, testCases + SIZE);

    //Determines if the number is prime and outputs
    for (unsigned int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); ++i) {
        unsigned int num = testCases[i];
        bool result = isPrime(num);
        std::cout << num << " is " << (result ? "prime" : "not prime") << std::endl;
    }

    return 0;
}