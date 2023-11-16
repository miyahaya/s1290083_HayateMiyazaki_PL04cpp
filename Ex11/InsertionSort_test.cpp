#include "InsertionSort.cpp"

int main()
{
    int arr[] = {5, 2, 9, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    PL04::Sort(std::begin(arr), std::end(arr));

    std::cout << "Sorted array in ascending order: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}