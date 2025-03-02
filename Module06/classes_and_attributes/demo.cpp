#include <iostream>

#include "character.hpp"

int main()
{
    Character character;

    std::cout << "Id counter: " << Character::id_counter << "\n";
    std::cout << "Id: " << character.id << "\n";
    std::cout << "Hit points: " << character.hit_points << "\n";
    std::cout << "Armor points: " << character.armor_points << "\n";

    Character::id_counter++;

    Character character1;

    character1.id = 2;
    character1.hit_points = 18;
    character1.armor_points = 10;

    std::cout << "Id counter: " << Character::id_counter << "\n";
    std::cout << "Id: " << character1.id << "\n";
    std::cout << "Hit points: " << character1.hit_points << "\n";
    std::cout << "Armor points: " << character1.armor_points << "\n";

    return 0;
}