#include <iostream>

int main()
{
    int x = 5;

    std::cout << "X in main: " << x << std::endl;

    {
        int x = 10;
        std::cout << "X in the first scope: " << x << std::endl;

        {
            int x = 15;
            std::cout << "X in the second scope: " << x << std::endl;
        }

        std::cout << "X in the first scope: " << x << std::endl;
    }  

    std::cout << "X in main: " << x << std::endl;

    return 0;
}