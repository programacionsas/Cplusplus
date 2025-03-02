#include <iostream>

void param_by_copy(int x)
{
    x = 10;
}

void param_by_ref(int& x)
{
    x = 10;
}

int main()
{
    int var = 5;

    std::cout << "Var antes de param_by_copy: " << var << "\n";
    param_by_copy(var);
    std::cout << "Var después de param_by_copy: " << var << "\n";
    param_by_ref(var);
    std::cout << "Var después de param_by_ref: " << var << "\n";

    return 0;
}