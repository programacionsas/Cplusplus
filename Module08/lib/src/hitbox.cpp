#include <lib/include/hitbox.hpp>

HitBox::HitBox(float x1, float y1, float x2, float y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

float HitBox::get_x1() const
{
    return this->x1;
}

float HitBox::get_y1() const
{
    return this->y1;
}

float HitBox::get_x2() const
{
    return this->x2;
}
    
float HitBox::get_y2() const
{
    return this->y2;
}

bool HitBox::collides(const HitBox& hb) const
{
    if (this->x1 > hb.x2 || this->x2 < hb.x1)   
    {
        return false;
    }

    if (this->y1 > hb.y2 || this->y2 < hb.y1)   
    {
        return false;
    }

    return true;
}