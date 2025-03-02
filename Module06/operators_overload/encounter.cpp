#include "encounter.hpp"
#include "character.hpp"

using namespace std::literals;

Encounter::Encounter(int _id)
    : id{_id}
{
    // Empty
}

int Encounter::get_id() const
{
    return this->id;
}

int FloorTrap::id_counter = 0;

FloorTrap::FloorTrap()
    : Encounter{++id_counter}
{
    // Empty
}

FloorTrap::FloorTrap(int dam)
    : Encounter{++id_counter}, damage{dam}
{
    // Empty
}

int FloorTrap::get_damage() const
{
    return this->damage;
}

void FloorTrap::play_out(Character* character)
{
    character->play_out_floor_trap(this);
}

std::string FloorTrap::to_string() const
{
    return "FloorTrap [id: "s + std::to_string(this->id)
        + ", damage: "s + std::to_string(this->damage)
        + "]"s;
}

int Monster::id_counter = 0;

Monster::Monster()
    : Encounter{++id_counter}
{
    // Empty
}

Monster::Monster(int dam, int hp)
    : Encounter{++id_counter}, damage{dam}, hit_points{hp}
{
    // Empty
}

int Monster::get_damage() const
{
    return this->damage;
}

int Monster::get_hit_points() const
{
    return this->hit_points;
}

void Monster::play_out(Character* character)
{
    character->play_out_monster(this);
}

std::string Monster::to_string() const
{
    return "Monster [id: "s + std::to_string(this->id)
        + ", damage: "s + std::to_string(this->damage)
        + ", hit_points: "s + std::to_string(this->hit_points)
        + "]"s;
}

int Potion::id_counter = 0;

Potion::Potion()
    : Encounter{++id_counter}
{
    // Empty
}

Potion::Potion(int hp, int mp)
    : Encounter{++id_counter}
{
    // Empty
}

int Potion::get_hit_points() const
{
    return this->hit_points;
}

int Potion::get_magic_points() const
{
    return this->magic_points;
}

void Potion::play_out(Character* character)
{
    character->play_out_potion(this);
}

std::string Potion::to_string() const
{
    return "Potion [id: "s + std::to_string(this->id)
        + ", hit_points: "s + std::to_string(this->hit_points)
        + ", magic_points: "s + std::to_string(this->magic_points)
        + "]"s;
}

int Armor::id_counter = 0;

Armor::Armor()
    : Encounter{++id_counter}
{
    // Empty
}

Armor::Armor(int ap)
    : Encounter{++id_counter}, armor_points{ap}
{
    // Empty
}

int Armor::get_armor_points() const
{
    return this->armor_points;
}

void Armor::play_out(Character* character)
{
    character->play_out_armor(this);
}

std::string Armor::to_string() const
{
    return "Armor [id: "s + std::to_string(this->id)
        + ", armor_points: "s + std::to_string(this->armor_points)
        + "]"s;
}
