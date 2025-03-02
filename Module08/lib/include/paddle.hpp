#ifndef PADDLE_HPP
#define PADDLE_HPP

class HitBox;

class Paddle
{
public:
    Paddle(float x, float y);

    HitBox build_hitbox() const;

    void update(float dt);

    void render() const;

    void set_velocity(float vy);

private:
    float x;
    float y;
    float vy;
};

#endif