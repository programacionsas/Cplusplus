#include <allegro5/allegro_primitives.h>

#include <settings.hpp>
#include <lib/include/pong_table.hpp>
#include <lib/include/hitbox.hpp>

PongTable::PongTable()
{
    this->player1 = std::make_unique<Paddle>(
        Settings::PADDLE_X_OFFSET, Settings::PADDLE_Y_OFFSET
    );

    this->player2 = std::make_unique<Paddle>(
        Settings::TABLE_WIDTH - Settings::PADDLE_WIDTH - Settings::PADDLE_X_OFFSET,
        Settings::TABLE_HEIGHT - Settings::PADDLE_HEIGHT - Settings::PADDLE_Y_OFFSET
    );

    this->ball = std::make_unique<Ball>(
        Settings::TABLE_WIDTH / 2 - Settings::BALL_SIZE / 2,
        Settings::TABLE_HEIGHT / 2 - Settings::BALL_SIZE / 2
    );

    this->player1_score = 0;
    this->player2_score = 0;
    this->serving_player = 1;
    this->winning_player = 0;

    this->state = State::Serving;

    srand(time(nullptr));
}

void PongTable::handle_input(const ALLEGRO_KEYBOARD_STATE& kb_state)
{
    if (this->state == State::Serving)
    {
        if (al_key_down(&kb_state, ALLEGRO_KEY_ENTER))
        {
            float ball_vx = rand() % 60 + 140;
            float ball_vy = rand() % 100 -50;
    
            if (this->serving_player == 2)
            {
                ball_vx *= -1.f;
            }

            this->ball->set_velocity(ball_vx, ball_vy);   

            this->state = State::Playing;
        }    
    }
    else if (this->state == State::Playing)
    {
        if (al_key_down(&kb_state, ALLEGRO_KEY_S))
        {
            this->player1->set_velocity(Settings::PADDLE_SPEED);
        }
        else if (al_key_down(&kb_state, ALLEGRO_KEY_W))
        {
            this->player1->set_velocity(-Settings::PADDLE_SPEED);
        }
        else
        {
            this->player1->set_velocity(0);
        }

        if (al_key_down(&kb_state, ALLEGRO_KEY_DOWN))
        {
            this->player2->set_velocity(Settings::PADDLE_SPEED);
        }
        else if (al_key_down(&kb_state, ALLEGRO_KEY_UP))
        {
            this->player2->set_velocity(-Settings::PADDLE_SPEED);
        }
        else
        {
            this->player2->set_velocity(0);
        }
    }
}

void PongTable::update(float dt)
{
    if (this->state != State::Playing)
    {
        return;
    }

    this->player1->update(dt);
    this->player2->update(dt);
    this->ball->update(dt);

    HitBox ball_hb = this->ball->build_hitbox();
    HitBox player1_hb = this->player1->build_hitbox();
    HitBox player2_hb = this->player2->build_hitbox();

    this->ball->solve_collisions(player1_hb, player2_hb);

    if (ball_hb.get_x1() > Settings::TABLE_WIDTH)
    {
        ++this->player1_score;
        this->serving_player = 2;

        if (this->player1_score == Settings::MAX_SCORE)
        {
            this->winning_player = 1;
            this->state = State::Done;
        }
        else
        {
            this->state = State::Serving;
            this->ball = std::make_unique<Ball>(
                Settings::TABLE_WIDTH / 2 - Settings::BALL_SIZE / 2,
                Settings::TABLE_HEIGHT / 2 - Settings::BALL_SIZE / 2
            );
        }
    }
    else if (ball_hb.get_x2() < 0)
    {
        ++this->player2_score;
        this->serving_player = 1;

        if (this->player2_score == Settings::MAX_SCORE)
        {
            this->winning_player = 2;
            this->state = State::Done;
        }
        else
        {
            this->state = State::Serving;
            this->ball = std::make_unique<Ball>(
                Settings::TABLE_WIDTH / 2 - Settings::BALL_SIZE / 2,
                Settings::TABLE_HEIGHT / 2 - Settings::BALL_SIZE / 2
            );
        }
    }
}

void PongTable::render() const
{
    al_draw_filled_rectangle(
        Settings::TABLE_WIDTH / 2 - Settings::MID_LINE_WIDTH / 2, 0,
        Settings::TABLE_WIDTH / 2 + Settings::MID_LINE_WIDTH / 2, Settings::TABLE_HEIGHT,
        al_map_rgb(255, 255, 255)
    );

    this->player1->render();
    this->player2->render();
    this->ball->render();

    std::string score_text = std::to_string(this->player1_score);
    al_draw_text(
        Settings::fonts["score"],
        al_map_rgb(255, 255, 255),
        Settings::TABLE_WIDTH / 2 - 50,
        Settings::TABLE_HEIGHT / 6,
        ALLEGRO_ALIGN_CENTER,
        score_text.c_str()
    );
    score_text = std::to_string(this->player2_score);
    al_draw_text(
        Settings::fonts["score"],
        al_map_rgb(255, 255, 255),
        Settings::TABLE_WIDTH / 2 + 50,
        Settings::TABLE_HEIGHT / 6,
        ALLEGRO_ALIGN_CENTER,
        score_text.c_str()
    );

    if (this->state == State::Serving)
    {
        al_draw_text(
            Settings::fonts["text"],
            al_map_rgb(255, 255, 255),
            Settings::TABLE_WIDTH / 2,
            Settings::TABLE_HEIGHT / 3 * 2,
            ALLEGRO_ALIGN_CENTER,
            "Press enter to serve!"
        );
    }
    if (this->state == State::Done)
    {
        std::string winning_text = std::string{"Player "} + std::to_string(this->winning_player) + " won!";
        al_draw_text(
            Settings::fonts["text"],
            al_map_rgb(255, 255, 255),
            Settings::TABLE_WIDTH / 2,
            Settings::TABLE_HEIGHT / 2,
            ALLEGRO_ALIGN_CENTER,
            winning_text.c_str()
        );
    }
}