#include <settings.hpp>

const fs::path Settings::ASSETS_PATH{"assets"};

const fs::path Settings::FONTS_PATH{Settings::ASSETS_PATH / "fonts"};

std::unordered_map<std::string, ALLEGRO_FONT*> Settings::fonts{};

void Settings::init()
{
    al_init_font_addon();
    al_init_ttf_addon();
    auto font_file = (Settings::FONTS_PATH / "font.ttf").string();
    Settings::fonts["text"] = al_load_ttf_font(font_file.c_str(), 16, ALLEGRO_TTF_MONOCHROME);
    Settings::fonts["score"] = al_load_ttf_font(font_file.c_str(), 32, ALLEGRO_TTF_MONOCHROME);
}

void Settings::close()
{
    for (auto &[font_name, font] : Settings::fonts)
    {
        al_destroy_font(font);
    }
    al_shutdown_ttf_addon();
    al_shutdown_font_addon();
}