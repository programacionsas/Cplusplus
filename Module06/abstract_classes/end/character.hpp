#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Encounter;
class FloorTrap;
class Monster;
class Potion;
class Armor;

class Character
{
public:
    Character(int _id);

    Character(int _id, int hp);

    bool is_dead() const;

    int get_id() const;

    int get_hit_points() const;

    void play_out_encounter(Encounter* encounter);

    virtual void play_out_floor_trap(FloorTrap* floor_trap) = 0;

    virtual void play_out_monster(Monster* monster) = 0;

    virtual void play_out_potion(Potion* potion);

    virtual void play_out_armor(Armor* armor) = 0;

    virtual std::string to_string() const = 0;

protected:
    static constexpr int max_hit_points = 50;

    int id = 1;
    int hit_points = 15;
};

class Knight : public Character
{
public:
    Knight();

    Knight(int hp, int ap);

    int get_armor_points() const;

    void play_out_floor_trap(FloorTrap* floor_trap) override;

    void play_out_monster(Monster* monster) override;

    void play_out_armor(Armor* armor) override;

    std::string to_string() const override;

private:
    void apply_damage(int dam);

    static constexpr int max_armor_points = 20;
    static int id_counter;
    
    int armor_points = 3;
};

class Wizard : public Character
{
public:
    Wizard();

    Wizard(int hp, int mp);

    int get_magic_points() const;

    void play_out_floor_trap(FloorTrap* floor_trap) override;

    void play_out_monster(Monster* monster) override;

    void play_out_potion(Potion* potion) override;

    void play_out_armor(Armor* armor) override;

    std::string to_string() const override;

private:
    static constexpr int max_magic_points = 20;
    static int id_counter;
    
    int magic_points = 10;
};

#endif