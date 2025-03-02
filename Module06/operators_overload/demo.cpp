#include <iostream>

#include "character.hpp"

int main()
{
    Knight k1{20, 10};
    Knight k2{20, 10};
    Knight k3{};

    k3 = k1;

    std::cout << "k1 = " << k1.to_string() << "\n";
    std::cout << "k2 = " << k2.to_string() << "\n";
    std::cout << "k3 = " << k3.to_string() << "\n";

    std::cout << std::boolalpha;
    std::cout << "k1 == k2? " << (k1 == k2) << "\n";
    std::cout << "k1 == k3? " << (k1 == k3) << "\n";

    std::cout << "k1 != k2? " << (k1 != k2) << "\n";
    std::cout << "k1 != k3? " << (k1 != k3) << "\n";

    return 0;
}