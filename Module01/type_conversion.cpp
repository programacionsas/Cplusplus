#include <iostream>

int main()
{
    int x = 5;
    int y = 2;

    std::cout << static_cast<float>(x) / y << '\n';

    const int min_age = 18;

    int& min_age_ref = const_cast<int&>(min_age);

    min_age_ref = 19;

    std::cout << "New min age: " << min_age_ref << '\n';

    return 0;
}