#include <iostream>

#include "character.hpp"
#include "encounter.hpp"

int main()
{
    Character character;
    Encounter encounter{25};

    std::cout << std::boolalpha;
    std::cout << "Before playing out encounter\n";
    std::cout << character.to_string() << "\n";
    std::cout << encounter.to_string() << "\n";
    std::cout << "Is character dead? " << character.is_dead() << "\n";

    character.play_out_encounter(&encounter);

    std::cout << "After playing out encounter\n";
    std::cout << character.to_string() << "\n";
    std::cout << encounter.to_string() << "\n";
    std::cout << "Is character dead? " << character.is_dead() << "\n";

    return 0;
}