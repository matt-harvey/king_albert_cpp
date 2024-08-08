#ifndef KING_ALBERT_CPP_COLOR_H
#define KING_ALBERT_CPP_COLOR_H

#include <iosfwd>

#include "AnsiColor.h"

namespace ka {

enum class CardColor {
    black,
    red
};

auto ansi_color_for(CardColor c) -> std::string;

} // namespace ka

#endif // KING_ALBERT_CPP_COLOR_H
