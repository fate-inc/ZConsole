#ifndef zconsole_h
#define zconsole_h

#include <iostream>
#include <string>
#include <algorithm>

namespace zconsole
{
    enum class text_color 
    {
        Default,
        Black,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White
    };

    void print(const std::string& text, text_color textColor = text_color::Default);
    void print(const std::string& text, int red, int green, int blue);
    void print(const std::string& text, const std::string& color);
}

#endif
