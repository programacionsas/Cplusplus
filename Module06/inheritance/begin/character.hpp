#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Encounter;

class Character
{
public:
    Character();

    Character(int hp, int ap);

    bool is_dead() const;

    int get_id() const;

    int get_hit_points() const;

    int get_armor_points() const;

    void play_out_encounter(Encounter* encounter);

    std::string to_string() const;

private:
    void apply_damage(int dam);

    static constexpr int max_hit_points = 50;
    static constexpr int max_armor_points = 20;
    static int id_counter;

    int id = 1;
    int hit_points = 15;
    int armor_points = 3;
};

#endif