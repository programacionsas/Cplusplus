#ifndef BALL_HPP
#define BALL_HPP

class HitBox;

class Ball
{
public:
    Ball(float x, float y);

    HitBox build_hitbox() const;

    void update(float dt);

    void render() const;

    void set_velocity(float vx, float vy);

    void solve_collisions(const HitBox& player1_hb, const HitBox& player2_hb);

private:
    float x;
    float y;
    float vx;
    float vy;
};

#endif
