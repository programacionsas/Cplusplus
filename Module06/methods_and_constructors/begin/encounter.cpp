#include "encounter.hpp"

using namespace std::literals;

int Encounter::id_counter = 0;

Encounter::Encounter()
    : id{++id_counter}
{
    // Empty
}

Encounter::Encounter(int dam)
    : id{++id_counter}, damage{dam}
{
    // Empty
}

int Encounter::get_id() const
{
    return this->id;
}

int Encounter::get_damage() const
{
    return this->damage;
}

std::string Encounter::to_string() const
{
    return "Encounter [id: "s + std::to_string(this->id)
        + ", damage: "s + std::to_string(this->damage) + "]"s;
}