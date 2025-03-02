#include <iostream>

using my_id_t = int;
using str_t = const char*;

int main()
{
    my_id_t id = 12345;
    str_t full_name = "Alejandro Mujica";

    std::cout << "Id: " << id << "\n";
    std::cout << "Full name: " << full_name << "\n";

    return 0;
}