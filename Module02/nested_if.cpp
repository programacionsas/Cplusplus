#include <iostream>

int main()
{
    int age;
    std::cout << "Introduzca su edad: ";
    std::cin >> age;

    if (age < 12)
    {
        std::cout << "El usuario es un niño\n";
    }
    else if (age < 18)
    {
        std::cout << "El usuario es adolescente\n";
    }
    else if (age < 60)
    {
        std::cout << "El usuario es adulto\n";
    }
    else
    {
        std::cout << "El usuario es de la tercera edad\n";
    }

    return 0;
}