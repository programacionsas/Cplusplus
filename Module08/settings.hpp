#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <filesystem>
#include <string>
#include <unordered_map>

#include <allegro5/allegro_ttf.h>

namespace fs = std::filesystem;

struct Settings
{
    static constexpr int WINDOW_WIDTH = 1280;
    static constexpr int WINDOW_HEIGHT = 720;
    static constexpr int TABLE_WIDTH = 432;
    static constexpr int TABLE_HEIGHT = 243;
    static constexpr int PADDLE_WIDTH = 5;
    static constexpr int PADDLE_HEIGHT = 20;
    static constexpr int PADDLE_X_OFFSET = 10;
    static constexpr int PADDLE_Y_OFFSET = 30;
    static constexpr int PADDLE_SPEED = 200;
    static constexpr int BALL_SIZE = 4;
    static constexpr int MID_LINE_WIDTH = 2;
    static constexpr float FPS = 60.f;
    static constexpr int MAX_SCORE = 5;

    static const fs::path ASSETS_PATH;
    static const fs::path FONTS_PATH;

    static std::unordered_map<std::string, ALLEGRO_FONT*> fonts;

    static void init();

    static void close();
};

#endif