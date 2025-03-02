#include <iostream>

#include <cstdlib>

void init(int& s, int& p)
{
    srand(time(nullptr));
    const int a = (rand() % 5) + 1;
    const int b = (rand() % 5) + 1;
    const int c = (rand() % 5) + 1;
    s = a + b + c;
    p = a * b * c;

    std::cout << "Debes adivinar el código de tres números enteros\n";
    std::cout << "La suma de los números es: " << s << '\n';
    std::cout << "El producto de los números es: " << p << '\n';
}

int main()
{
    int sum;
    int prod;

    init(sum, prod);

    int in_a;
    int in_b;
    int in_c;

    int counter = 3;

    do
    {
        std::cout << "Introduzca el primer número: ";
        std::cin >> in_a;
        std::cout << "Introduzca el segundo número: ";
        std::cin >> in_b;
        std::cout << "Introduzca el tercer número: ";
        std::cin >> in_c;

        int in_sum = in_a + in_b + in_c;
        int in_prod = in_a * in_b * in_c;

        if (in_sum == sum && in_prod == prod)
        {
            std::cout << "El código introducido es correcto\n";
            break;
        }
        else
        {
            counter--;
            std::cout << "El código introducido es incorrecto";
            
            if (counter > 0)
            {
                std::cout << ", intente de nuevo\n"; 
            }
            else
            {
                std::cout << ".\n";
            }        
            std::cout << "Te quedan " << counter << " oportunidad";

            if (counter == 1)
            {
                std::cout << ".\n";
            }
            else
            {
                std::cout << "es.\n";
            }
        }
    }
    while (counter > 0);

    if (counter == 0)
    {
        std::cout << "Has perdido\n";
    }
    else
    {
        std::cout << "Has ganado\n";
    }

    return 0;
}