#ifndef HITBOX_HPP
#define HITBOX_HPP

class HitBox
{
public:
    HitBox(float x1, float y1, float x2, float y2);

    float get_x1() const;

    float get_y1() const;

    float get_x2() const;
    
    float get_y2() const;

    bool collides(const HitBox& hb) const;

private:
    float x1;
    float y1;
    float x2;
    float y2;
};

#endif
