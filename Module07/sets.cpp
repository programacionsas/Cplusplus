#include <iostream>

#include <set>
#include <unordered_set>

int main()
{
    std::set<int> s;

    s.insert(10);
    s.insert(5);
    s.insert(3);
    s.insert(82);
    s.insert(25);
    s.insert(44);
    s.insert(44);
    s.insert(44);
    s.insert(44);
    s.insert(44);
    s.insert(98);
    s.insert(12);

    std::cout << "Set\n";

    for (int item : s)
    {
        std::cout << item << "\n";
    }

    std::multiset<int> ms;

    ms.insert(10);
    ms.insert(5);
    ms.insert(3);
    ms.insert(82);
    ms.insert(25);
    ms.insert(44);
    ms.insert(44);
    ms.insert(44);
    ms.insert(44);
    ms.insert(44);
    ms.insert(98);
    ms.insert(12);

    std::cout << "\nMulti set\n";

    for (int item : ms)
    {
        std::cout << item << "\n";
    }

    std::unordered_set<int> us;

    us.insert(10);
    us.insert(5);
    us.insert(3);
    us.insert(82);
    us.insert(25);
    us.insert(44);
    us.insert(44);
    us.insert(44);
    us.insert(44);
    us.insert(44);
    us.insert(98);
    us.insert(12);

    std::cout << "\nUnordered set\n";

    for (int item : us)
    {
        std::cout << item << "\n";
    }

    std::unordered_multiset<int> ums;

    ums.insert(10);
    ums.insert(5);
    ums.insert(3);
    ums.insert(82);
    ums.insert(25);
    ums.insert(44);
    ums.insert(44);
    ums.insert(44);
    ums.insert(44);
    ums.insert(44);
    ums.insert(98);
    ums.insert(12);

    std::cout << "\nUnordered multi set\n";

    for (int item : ums)
    {
        std::cout << item << "\n";
    }

    return 0;
}