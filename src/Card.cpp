#include "Card.h"

#include <iostream>

namespace ka {

auto operator<<(std::ostream &o, Card card) -> std::ostream & {
    ansi_color::printer const _ { o, ansi_color_for(card.color()) };
    o << card.rank() << card.suit();
    return o;
}

} // namespace ka
