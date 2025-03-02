#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Vector original\n";

    std::for_each(
        v.begin(),
        v.end(),
        [] (int item)
        {
            std::cout << item << "\n";
        }
    );

    std::vector<int> f;

    std::copy_if(
        v.begin(),
        v.end(),
        std::back_inserter(f),
        [] (int item)
        {
            return item % 2 == 0;
        }
    );

    std::cout << "\nVector de números pares\n";

    for (auto item : f)
    {
        std::cout << item << "\n";
    }

    std::vector<int> t(v.size());

    std::transform(
        v.begin(),
        v.end(),
        t.begin(),
        [] (int item)
        {
            return item * item;
        }
    );

    std::cout << "\nVector de números elevados al cuadrado\n";

    for (auto item : t)
    {
        std::cout << item << "\n";
    }

    int sum = std::accumulate(
        v.begin(),
        v.end(),
        0,
        [] (int acc, int item)
        {
            return acc + item;
        }
    );

    std::cout << "\nSum = " << sum << "\n";

    return 0;
}