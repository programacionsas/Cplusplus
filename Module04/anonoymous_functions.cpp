#include <iostream>

int main()
{
    // Anatomía de una función anónima
    // [] (tipo1 param1, tipo2 param2 ...) { cuerpo de la función }

    auto sum = [] (int a, int b)
    {
        return a + b;
    };

    int x = 5;
    int y = 3;

    auto use_sum_and_print_result = [sum, x, y] ()
    {
        std::cout << x << " + " << y << " = " << sum(x, y) << "\n";
    };

    use_sum_and_print_result();

    return 0;
}