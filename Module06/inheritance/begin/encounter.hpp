#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <memory>
#include <string>

class Character;

class Encounter
{
public:
    Encounter(int _id);

    int get_id() const;

    void play_out(Character* character);

    std::string to_string() const;

protected:
    int id = 1;
};

class FloorTrap : public Encounter
{
public:
    FloorTrap();

    FloorTrap(int dam);

    int get_damage() const;

    void play_out(Character* character);

    std::string to_string() const;

private:
    static int id_counter;

    int damage = 3;
};

class Monster : public Encounter
{
public:
    Monster(); 

    Monster(int dam, int hp);

    int get_damage() const;

    int get_hit_points() const;

    void play_out(Character* character);

    std::string to_string() const;

private:
    static int id_counter;

    int damage = 5;
    int hit_points = 3;
};

class Potion : public Encounter
{
public:
    Potion();

    Potion(int hp, int mp);

    int get_hit_points() const;

    int get_magic_points() const;
    
    void play_out(Character* character);

    std::string to_string() const;

private:
    static int id_counter;

    int hit_points = 5;
    int magic_points = 5;
};

class Armor : public Encounter
{
public:
    Armor();

    Armor(int ap);

    int get_armor_points() const;
    
    void play_out(Character* character);

    std::string to_string() const;

private:
    static int id_counter;
    
    int armor_points = 10;
};

#endif