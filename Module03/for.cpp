#include <iostream>

int main()
{
    constexpr int num_lines = 10;

    // for (inicialializar variales; expresión booleana; incremento)

    /*
        Otros operadores aritméticos

        int i;

        i = i + 1;
        i += 1;
        i++
        ++i
    */

    for (int i = 0; i < num_lines; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }

        std::cout << i << " No debo patinar dentro de la escuela\n";
    }

    std::cout << "Castigo completado\n";

    return 0;
}