#include <iostream>

int main()
{
    // while (expresión booleana) { }

    char harry_got_message = 'N';

    while (harry_got_message != 'S')
    {
        std::cout << "No debo decir mentiras\n";

        std::cout << "Harry obtuvo el mensaje? ";
        std::cin >> harry_got_message;
    }

    std::cout << "Castigo completado\n";

    return 0;
}