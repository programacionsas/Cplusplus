#include <iostream>

// Anatomía de una función
// tipo_de_dato_que_devuelve nombre_funcion(tipo1 var1, tipo2 var2,...) { cuerpo de la función }
// Anatomía de un procedimiento
// void nombre_funcion(tipo1 var1, tipo2 var2,...) { cuerpo de la función }

int sum(int a, int b)
{
    int result = a + b;
    return result;
}

void print_hello_world()
{
    std::cout <<  "Hello, World!\n";
}

int main()
{
    print_hello_world();
    std::cout << "5 + 3 = " << sum(5, 3) << "\n";
    return 0;
}