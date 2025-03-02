#include <iostream>

#include "character.hpp"
#include "encounter.hpp"

int main()
{
    std::shared_ptr<Character> knight = std::make_shared<Knight>(15, 3);
    std::cout << "Created " << knight->to_string() << "\n";

    std::shared_ptr<Character> wizard = std::make_shared<Wizard>(10, 2);
    std::cout << "Created " << wizard->to_string() << "\n";

    std::shared_ptr<Encounter> floor_trap = std::make_shared<FloorTrap>(3);
    std::cout << "Created " << floor_trap->to_string() << "\n";

    std::shared_ptr<Encounter> monster = std::make_shared<Monster>(5, 3);
    std::cout << "Created " << monster->to_string() << "\n";

    std::shared_ptr<Encounter> potion = std::make_shared<Potion>(5, 5);
    std::cout << "Created " << potion->to_string() << "\n";

    std::shared_ptr<Encounter> armor = std::make_shared<Armor>(10);
    std::cout << "Created " << armor->to_string() << "\n\n";

    std::cout << "Knight vs FloorTrap\n";
    knight->play_out_encounter(floor_trap.get());
    std::cout << knight->to_string() << "\n";
    std::cout << floor_trap->to_string() << "\n";

    std::cout << "Knight vs Monster\n";
    knight->play_out_encounter(monster.get());
    std::cout << knight->to_string() << "\n";
    std::cout << monster->to_string() << "\n";

    std::cout << "Knight vs Potion\n";
    knight->play_out_encounter(potion.get());
    std::cout << knight->to_string() << "\n";
    std::cout << potion->to_string() << "\n";

    std::cout << "Knight vs Armor\n";
    knight->play_out_encounter(armor.get());
    std::cout << knight->to_string() << "\n";
    std::cout << armor->to_string() << "\n";

    return 0;
}