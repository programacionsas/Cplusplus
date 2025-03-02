#include <iostream>

int main()
{
    // Anatomía de un apuntador tipo_de_dato* var_name;

    int x = 42;
    int y = 50;

    int* ptr = &x;

    std::cout << "Valor de ptr: " << ptr << "\n";
    std::cout << "Dirección de memoria de x: " << &x << "\n";
    std::cout << "Dirección de memoria de y: " << &y << "\n";
    std::cout << "Valor apuntado por ptr: " << *ptr << "\n"; 
    std::cout << "Valor de x antes de modificar ptr: " << x << "\n";
    std::cout << "Valor de y antes de modificar ptr: " << y << "\n\n";

    *ptr = 45;

    std::cout << "Valor de ptr: " << ptr << "\n";
    std::cout << "Dirección de memoria de x: " << &x << "\n";
    std::cout << "Dirección de memoria de y: " << &y << "\n";
    std::cout << "Valor apuntado por ptr: " << *ptr << "\n"; 
    std::cout << "Valor de x después de modificar ptr: " << x << "\n";
    std::cout << "Valor de y después de modificar ptr: " << y << "\n\n";

    ptr = &y;

    std::cout << "Valor de ptr: " << ptr << "\n";
    std::cout << "Dirección de memoria de x: " << &x << "\n";
    std::cout << "Dirección de memoria de y: " << &y << "\n";
    std::cout << "Valor apuntado por ptr: " << *ptr << "\n"; 
    std::cout << "Valor de x después de modificar ptr: " << x << "\n";
    std::cout << "Valor de y después de modificar ptr: " << y << "\n\n";

    *ptr = 55;

    std::cout << "Valor de ptr: " << ptr << "\n";
    std::cout << "Dirección de memoria de x: " << &x << "\n";
    std::cout << "Dirección de memoria de y: " << &y << "\n";
    std::cout << "Valor apuntado por ptr: " << *ptr << "\n"; 
    std::cout << "Valor de x después de modificar ptr: " << x << "\n";
    std::cout << "Valor de y después de modificar ptr: " << y << "\n\n";

    return 0;
}