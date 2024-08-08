#include "../include/CardColor.h"

#include <iostream>

namespace ka {

auto ansi_color_for(CardColor c) -> std::string {
    switch (c) {
    case CardColor::black:
        return ansi_color::black;
    case CardColor::red:
    default:
        return ansi_color::red;
    }
}

} // namespace ka