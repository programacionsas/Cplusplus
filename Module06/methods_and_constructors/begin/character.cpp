#include "character.hpp"

int Character::id_counter = 0;

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

bool Character::is_dead() const
{
    return this->hit_points <= 0;
}

void Character::apply_damage(int damage)
{
    if (this->armor_points == 0)
    {
        this->hit_points -= damage;
    }
    else if (damage > this->armor_points)
    {
        int new_damage = damage - this->armor_points;
        this->armor_points = 0;
        this->hit_points -= new_damage;
    }
    else
    {
        this->armor_points -= damage;
    }
}
