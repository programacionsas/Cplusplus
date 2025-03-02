#include <allegro5/allegro_primitives.h>

#include <settings.hpp>
#include <lib/include/paddle.hpp>
#include <lib/include/hitbox.hpp>

Paddle::Paddle(float x, float y)
{
    this->x = x;
    this->y = y;
    this->vy = 0.f;
}

HitBox Paddle::build_hitbox() const
{
    HitBox hitbox{
        this->x,
        this->y,
        this->x + Settings::PADDLE_WIDTH,
        this->y + Settings::PADDLE_HEIGHT
    };
    return hitbox;
}

void Paddle::update(float dt)
{
    this->y = this->y + this->vy * dt;

    if (this->y <= 0.f)
    {
        this->y = 0.f;
    }
    else if (this->y + Settings::PADDLE_HEIGHT >= Settings::TABLE_HEIGHT)
    {
        this->y = Settings::TABLE_HEIGHT - Settings::PADDLE_HEIGHT;
    }
}

void Paddle::render() const
{
    al_draw_filled_rectangle(
        this->x, this->y,
        this->x + Settings::PADDLE_WIDTH,
        this->y + Settings::PADDLE_HEIGHT,
        al_map_rgb(255, 255, 255)
    );
}

void Paddle::set_velocity(float vy)
{
    this->vy = vy;
}