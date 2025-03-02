#include <iostream>

int main()
{
    int opt;

    do
    {
        std::cout << "1- Primera opción\n";
        std::cout << "2- Segunda opción\n";
        std::cout << "3- Tercera opción\n";
        std::cout << "4- Cuarta opción\n";
        std::cout << "5- Salir\n";
        std::cout << "Elija una opción: ";
        std::cin >> opt;

        switch (opt)
        {
            case 1:
                std::cout << "El usuario eligió la primera opción\n";
                break;
            case 2:
                std::cout << "El usuario eligió la segunda opción\n";
                break;
            case 3:
                std::cout << "El usuario eligió la tercera opción\n";
                break;
            case 4:
                std::cout << "El usuario eligió la cuarta opción\n";
                break;
            case 5:
                break;
            default:
                std::cout << "El usuario eligió una opción no válida\n";
                break;
        }
    }
    while (opt != 5);

    std::cout << "Aplicación terminada\n";

    return 0;
}