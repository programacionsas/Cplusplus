#include <iostream>

int main()
{
    // Comentario de una línea
    /*
        Comentario de varias líneas
    */

   /*
    Numéricos: Enteros (int) y reales (float)
        Operaciones aritméticas: + - * / %
    Booleanos: true o false
        Operaciones booleanas: And (&&), Or (||), Not (!)
    Carácter: char
    Cadena de caracteres 
   */

    std::cout << 5.0f / 2 << "\n";

    std::cout << std::boolalpha;
    std::cout << true << "\n";
    std::cout << false << "\n";
    std::cout << !false << "\n";
    std::cout << (true && true) << "\n";
    std::cout << (false && true) << "\n";
    std::cout << (false || false) << "\n";
    std::cout << (false || true) << "\n";

    std::cout << 'a' << '\n';
    std::cout << "Hello World! & / % *\n";

    return 0;
}