#include "character.hpp"

#include "encounter.hpp"

using namespace std::literals;

Character::Character(int _id)
    : id{_id}
{
    // Empty
}

Character::Character(int _id, int hp)
    : id{_id}, hit_points{hp}
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

void Character::play_out_encounter(Encounter* encounter)
{
    encounter->play_out(this);
}

void Character::play_out_potion(Potion* potion)
{
    this->hit_points += potion->get_hit_points();

    if (this->hit_points > Character::max_hit_points)
    {
        this->hit_points = Character::max_hit_points;
    }
}

int Knight::id_counter = 0;

Knight::Knight()
    : Character{++id_counter}
{
    // Empty
}

Knight::Knight(int hp, int ap)
    : Character{++id_counter, hp}, armor_points{ap}
{
    // Empty
}

int Knight::get_armor_points() const
{
    return this->armor_points;
}

void Knight::play_out_floor_trap(FloorTrap* floor_trap)
{
    this->apply_damage(floor_trap->get_damage());
}

void Knight::play_out_monster(Monster* monster)
{
    this->apply_damage(monster->get_damage());
}

void Knight::play_out_armor(Armor* armor)
{
    this->armor_points += armor->get_armor_points();

    if (this->armor_points > Knight::max_armor_points)
    {
        this->armor_points = Knight::max_armor_points;
    }
}

std::string Knight::to_string() const
{
    return "Knight [id: "s + std::to_string(this->id)
        + ", hit_points: "s + std::to_string(this->hit_points)
        + ", armor_points: "s + std::to_string(this->armor_points)
        + "]"s;
}

void Knight::apply_damage(int dam)
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

int Wizard::id_counter = 0;

Wizard::Wizard()
    : Character{++id_counter}
{
    // Empty
}

Wizard::Wizard(int hp, int mp)
    : Character{++id_counter, hp}, magic_points{mp}
{
    // Empty
}

int Wizard::get_magic_points() const
{
    return this->magic_points;
}

void Wizard::play_out_floor_trap(FloorTrap* floor_trap)
{
    if (this->magic_points > 0)
    {
        this->magic_points--;
    }
    else
    {
        this->hit_points -= floor_trap->get_damage();
    }
}

void Wizard::play_out_monster(Monster* monster)
{
    this->magic_points -= monster->get_hit_points();

    if (this->magic_points < 0)
    {
        this->hit_points = 0;
    }
}

void Wizard::play_out_potion(Potion* potion)
{
    Character::play_out_potion(potion);

    this->magic_points += potion->get_magic_points();

    if (this->magic_points > Wizard::max_magic_points)
    {
        this->magic_points = Wizard::max_magic_points;
    }
}

void Wizard::play_out_armor(Armor* armor)
{
    // Nothing to do
}

std::string Wizard::to_string() const
{
    return "Wizard [id: "s + std::to_string(this->id)
        + ", hit_points: "s + std::to_string(this->hit_points)
        + ", magic_points: "s + std::to_string(this->magic_points)
        + "]"s;
}
