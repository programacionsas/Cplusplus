#ifndef GAME_HPP
#define GAME_HPP

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

#include <lib/include/pong_table.hpp>

class PongGame
{
public:
    PongGame();

    ~PongGame();

    void exec();

private:
    void handle_events();

    void update(float dt);

    void render();

    bool running;
    bool redraw;

    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY* display;
    ALLEGRO_BITMAP* render_surface;
    ALLEGRO_EVENT event;

    PongTable pong_table;
};

#endif