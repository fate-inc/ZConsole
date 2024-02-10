#include "zconsole.h"

namespace zconsole
{
    void print(const std::string& text, text_color textColor)
    {
        const char* color_codes[] = {
            "\033[0m", "\033[30m", "\033[31m", "\033[32m",
            "\033[33m", "\033[34m", "\033[35m", "\033[36m", "\033[37m"
        };

        const char* color_code = (textColor >= text_color::Black && textColor <= text_color::White) ?
            color_codes[static_cast<int>(textColor)] :
            color_codes[0];

        std::cout << "[ZConsole] " << color_code << text << "\033[0m" << std::endl; // we don't print the color if there's none lmao
    }

    void print(const std::string& text, int red, int green, int blue)
    {
        red = std::clamp(red, 0, 255);
        green = std::clamp(green, 0, 255);
        blue = std::clamp(blue, 0, 255);

        std::cout << "\033[38;2;" << red << ";" << green << ";" << blue << "m[ZConsole] " << text << "\033[0m" << std::endl;
    }

    void print(const std::string& text, const std::string& color)
    {
        int red, green, blue;

        color[0] == '#' ?
            (color.length() == 7 && sscanf_s(color.c_str(), "#%02x%02x%02x", &red, &green, &blue) == 3 ?
                print(text, red, green, blue) :
                print(text, text_color::Default)) :
            (sscanf_s(color.c_str(), "%d,%d,%d", &red, &green, &blue) == 3 ?
                print(text, red, green, blue) :
                print(text, text_color::Default));
    }
}