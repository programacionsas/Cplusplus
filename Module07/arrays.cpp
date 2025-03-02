#include <array>
#include <iostream>

int main()
{
    std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << std::endl;
    }

    for (auto i = arr.begin(); i != arr.end(); ++i)
    {
        std::cout << *i << "\n";
    }

    for (int item : arr)
    {
        std::cout << item << "\n";
    }

    return 0;
}