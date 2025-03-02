#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <memory>
#include <string>

class Encounter
{
public:
    Encounter();

    Encounter(int dam);

    int get_id() const;

    int get_damage() const;

    std::string to_string() const;

private:
    static int id_counter;

    int id = 1;
    int damage = 3;
};

#endif