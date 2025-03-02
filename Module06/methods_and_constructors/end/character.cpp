#include "character.hpp"

#include "encounter.hpp"

using namespace std::literals;

int Character::id_counter = 0;

Character::Character()
    : id{++id_counter}
{
    // Empty
}

Character::Character(int hp, int ap)
    : id{++id_counter}, hit_points{hp}, armor_points{ap}
{
    // Empty
}

bool Character::is_dead() const
{
    return this->hit_points <= 0;
}

int Character::get_id() const
{
    return this->id;
}

int Character::get_hit_points() const
{
    return this->hit_points;
}

int Character::get_armor_points() const
{
    return this->armor_points;
}

void Character::play_out_encounter(Encounter* encounter)
{
    this->apply_damage(encounter->get_damage());
}

std::string Character::to_string() const
{
    return "Character [id: "s + std::to_string(this->id)
        + ", hit_points: "s + std::to_string(this->hit_points)
        + ", armor_points: "s + std::to_string(this->armor_points)
        + "]"s;
}

void Character::apply_damage(int dam)
{
    if (this->armor_points == 0)
    {
        this->hit_points -= dam;
    }
    else if (dam > this->armor_points)
    {
        int new_dam = dam - this->armor_points;
        this->armor_points = 0;
        this->hit_points -= new_dam;
    }
    else
    {
        this->armor_points -= dam;
    }
}
