#include <iostream>

int main()
{
    int x = 42;
    int y = 50;

    int& x_ref = x;

    std::cout << "Valor de x_ref antes de modificarlo: " << x_ref << "\n";
    std::cout << "Valor de x antes de modificar x_ref: " << x << "\n";
    std::cout << "Valor de y antes de modificar x_ref: " << y << "\n\n";

    x_ref = 45;

    std::cout << "Valor de x_ref después de asignarle 45: " << x_ref << "\n";
    std::cout << "Valor de x después de asignarle 45 a x_ref: " << x << "\n";
    std::cout << "Valor de y después de asignarle 45 a x_ref: " << y << "\n\n";

    x_ref = y;

    std::cout << "Valor de x_ref después de asignarle y: " << x_ref << "\n";
    std::cout << "Valor de x después de asignarle y a x_ref: " << x << "\n";
    std::cout << "Valor de y después de asignarle y a x_ref: " << y << "\n\n";

    x_ref = 48;

    std::cout << "Valor de x_ref después de asignarle 48: " << x_ref << "\n";
    std::cout << "Valor de x después de asignarle 48 a x_ref: " << x << "\n";
    std::cout << "Valor de y después de asignarle 48 a x_ref: " << y << "\n\n";

    return 0;
}