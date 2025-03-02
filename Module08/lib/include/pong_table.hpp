#ifndef PONGTABLE_HPP
#define PONGTABLE_HPP

#include <memory>

#include <allegro5/keyboard.h>

#include <lib/include/ball.hpp>
#include <lib/include/paddle.hpp>

class PongTable
{
public:
    enum class State
    {
        Serving,
        Playing,
        Done
    };

    PongTable();

    void handle_input(const ALLEGRO_KEYBOARD_STATE& kb_state);

    void update(float dt);

    void render() const;

private:
    std::unique_ptr<Paddle> player1;
    std::unique_ptr<Paddle> player2;
    std::unique_ptr<Ball> ball;

    int player1_score;
    int player2_score;
    int serving_player;
    int winning_player;

    State state;
};

#endif