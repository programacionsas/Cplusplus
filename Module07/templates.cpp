#include <iostream>

template <typename T1, typename T2>
T1 add(T1 a, T2 b)
{
    return a + b;
}

template <typename T1, typename T2>
struct MyPair
{
    T1 first;
    T2 second;
};

int main()
{
    std::cout << "3 + 5 = " << add(3, 5) << "\n";
    std::cout << "3.2 + 5.4 = " << add(3.2f, 5.4f) << "\n";
    std::cout << "3.2 + 5 = " << add(3, 5.4f) << "\n";

    MyPair<int, float> p;
    p.first = 5;
    p.second = 4;

    return 0;
}

