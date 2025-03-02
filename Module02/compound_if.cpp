#include <iostream>

int main()
{
    /*
        Anatomía del if

        if (expression)
           bloque de código en caso de que expression sea true
        else
            bloque de código en caso de que expression sea false
    */

    constexpr int legal_age = 18;
    int age;
    std::cout << "Introduzca la edad del comprador: ";
    std::cin >> age;

    if (age >= legal_age)
    {
        std::cout << "El comprador puede adquirir las bebidas\n";
    }
    else
    {
        std::cout << "El comprador NO puede adquirir las bebidas\n";
    }

    std::cout << "El comprador terminó sus compras\n";

    return 0;
}