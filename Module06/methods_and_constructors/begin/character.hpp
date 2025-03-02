#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
    int get_id() const;

    int get_hit_points() const;

    int get_armor_points() const;

    bool is_dead() const;

    void apply_damage(int damage);

private:
    static constexpr int max_hit_points = 50;
    static constexpr int max_armor_points = 20;
    static int id_counter;

    int id = 1;
    int hit_points = 15;
    int armor_points = 3;
};

#endif