#include <iostream>
#include <vector>

int main()
{
    std::vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    arr.push_back(11);
    arr.insert(arr.begin(), 0);

    for (int item : arr)
    {
        std::cout << item << "\n";
    }

    arr.pop_back();

    arr.back();
    arr.front();

    return 0;
}