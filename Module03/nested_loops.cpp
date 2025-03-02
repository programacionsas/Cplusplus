#include <iostream>

int main()
{
    // for (inicializar; expresión booleana; incrementos)

    constexpr int num_repeat = 5;
    constexpr int num_circuit = 4;

    for (int i = 0; i < num_circuit; i++)
    {
        std::cout << "Ejecutando circuito " << i + 1 << "\n";
        for (int j = 0; j < num_repeat; j++)
        {
            std::cout << "Ejecutando ejercicio " << j + 1 << "\n";
        }
    }

    return 0;
}