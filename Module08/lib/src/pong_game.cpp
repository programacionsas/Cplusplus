#include <settings.hpp>

#include <lib/include/pong_game.hpp>

PongGame::PongGame()
{
    al_init();
    al_install_keyboard();
    al_init_primitives_addon();

    this->timer = al_create_timer(1.f / Settings::FPS);
    this->queue = al_create_event_queue();
    this->display = al_create_display(Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT);
    this->render_surface = al_create_bitmap(Settings::TABLE_WIDTH, Settings::TABLE_HEIGHT);

    Settings::init();

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(this->display));
    al_register_event_source(queue, al_get_timer_event_source(this->timer));
}

PongGame::~PongGame()
{
    Settings::close();
    al_shutdown_primitives_addon();
    al_destroy_bitmap(this->render_surface);
    al_destroy_display(this->display);
    al_destroy_timer(this->timer);
    al_destroy_event_queue(this->queue);
}

void PongGame::exec()
{
    this->running = true;

    this->redraw = true;
    
    al_start_timer(this->timer);
    float last_frame_time = al_get_time();

    while (this->running)
    {
        this->handle_events();

        if (this->redraw && al_is_event_queue_empty(this->queue))
        {
            float current_frame_time = al_get_time();
            float dt = current_frame_time - last_frame_time;

            this->update(dt);
            
            this->render();

            redraw = false;
            last_frame_time = current_frame_time;
        }
    }
}

void PongGame::handle_events()
{
    al_wait_for_event(this->queue, &event);

    if (event.type == ALLEGRO_EVENT_TIMER)
    {
        this->redraw = true;
    }
    else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
        this->running = false;
    }
    else if (event.type == ALLEGRO_EVENT_KEY_DOWN || event.type == ALLEGRO_EVENT_KEY_UP)
    {
        ALLEGRO_KEYBOARD_STATE keyboard_state;
        al_get_keyboard_state(&keyboard_state);
        this->pong_table.handle_input(keyboard_state);
    }
}

void PongGame::update(float dt)
{
    this->pong_table.update(dt);
}

void PongGame::render()
{
    // All of the following draws will be on render_surface
    al_set_target_bitmap(this->render_surface);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    this->pong_table.render();

    // Set the display bitmap as current to render
    al_set_target_bitmap(al_get_backbuffer(this->display));
    
    al_draw_scaled_bitmap(
        this->render_surface,
        0, 0, Settings::TABLE_WIDTH, Settings::TABLE_HEIGHT,   // Source x, y, width, height
        0, 0, Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT, // Target x, y, width, height
        0 // flags
    );
    al_flip_display();
}