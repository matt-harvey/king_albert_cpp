#ifndef KING_ALBERT_CPP_COLOR_H
#define KING_ALBERT_CPP_COLOR_H

#include "AnsiColor.h"
#include <iosfwd>

namespace ka {

enum class CardColor { black, red };

auto ansi_color_for(CardColor c) -> std::string;

} // ka

#endif // KING_ALBERT_CPP_COLOR_H
