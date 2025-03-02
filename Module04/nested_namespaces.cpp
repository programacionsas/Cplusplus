#include <iostream>

namespace MyNamespace
{
    int increment(int x)
    {
        return x + 1;
    }

    namespace Math
    {
        int sum(int a, int b)
        {
            return a + b;
        }

        int abs(int x)
        {
            if (x < 0)
            {
                return -x;
            }

            return x;
        }
    }

    namespace Output
    {
        void print_hello_world()
        {
            std::cout << "Hello, World!\n";
        }

        void greet(const char* name)
        {
            std::cout << "Hello " << name << "\n";
        }
    }
}

int main()
{
    std::cout << "5 + 1 = " << MyNamespace::increment(5) << "\n";

    MyNamespace::Output::greet("EdTeam");

    std::cout << "5 + 3 = " << MyNamespace::Math::sum(5, 3) << "\n";

    return 0;
}