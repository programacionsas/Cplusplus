#include <iostream>

int main()
{
    constexpr int legal_age = 18;

    int age;
    std::cout << "Introduzca la edad del comprador: ";
    std::cin >> age;

    /*
        Anatomía de la sentencia if

        if (expression)
            bloque_de_código que se ejecuta en caso de que expression sea true

    */

    if (age >= legal_age)
    {
        std::cout << "El comprador puede adquirir las bebidas\n";
    }
        
    std::cout << "El comprador terminó sus compras\n";

    return 0;
}