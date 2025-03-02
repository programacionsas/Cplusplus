#include <allegro5/allegro_primitives.h>

#include <settings.hpp>
#include <lib/include/ball.hpp>
#include <lib/include/hitbox.hpp>

Ball::Ball(float x, float y)
{
    this->x = x;
    this->y = y;
    this->vx = 0.f;
    this->vy = 0.f;
}

HitBox Ball::build_hitbox() const
{
    HitBox hitbox{
        this->x,
        this->y,
        this->x + Settings::BALL_SIZE,
        this->y + Settings::BALL_SIZE
    };
    return hitbox;
}

void Ball::update(float dt)
{
    this->x = this->x + this->vx * dt;
    this->y = this->y + this->vy * dt;
}

void Ball::render() const
{
    al_draw_filled_rectangle(
        this->x, this->y,
        this->x + Settings::BALL_SIZE,
        this->y + Settings::BALL_SIZE,
        al_map_rgb(255, 255, 255)
    );
}

void Ball::set_velocity(float vx, float vy)
{
    this->vx = vx;
    this->vy = vy;
}

void Ball::solve_collisions(const HitBox& player1_hb, const HitBox& player2_hb)
{
    HitBox hb = this->build_hitbox();

    // Solve collisions with table 
    if (hb.get_y1() <= 0)
    {
        this->y = 0;
        this->vy *= -1;
    }
    else if (hb.get_y2() >= Settings::TABLE_HEIGHT)
    {
        this->y = Settings::TABLE_HEIGHT - Settings::BALL_SIZE;
        this->vy *= -1;
    }

    // Solve collision with players
    if (hb.collides(player1_hb))
    {
        this->x = player1_hb.get_x2();
        this->vx *= -1.03;

        if (this->vy < 0)
        {
            this->vy = -(rand() % 140 + 10);
        }
        else
        {
            this->vy = rand() % 140 + 10;
        }
    }
    else if (hb.collides(player2_hb))
    {
        this->x = player2_hb.get_x1() - Settings::BALL_SIZE;
        this->vx *= -1.03;

        if (this->vy < 0)
        {
            this->vy = -(rand() % 140 + 10);
        }
        else
        {
            this->vy = rand() % 140 + 10;
        }
    }
}