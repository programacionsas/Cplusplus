#include <iostream>

int main()
{
    // do { bloque de código } while (expresión booleana);

    char harry_got_message;

    do
    {
        std::cout << "No debo decir mentiras\n";

        std::cout << "Harry obtuvo el mensaje? ";
        std::cin >> harry_got_message;
    }
    while (harry_got_message != 'S');

    std::cout << "Castigo completado\n";

    return 0;
}