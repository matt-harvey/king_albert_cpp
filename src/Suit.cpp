#include "Suit.h"

#include <cassert>
#include <ostream>

namespace ka {

auto color(Suit suit) -> CardColor {
    switch (suit) {
    case Suit::spades:
    case Suit::clubs:
        return CardColor::black;
    case Suit::hearts:
    case Suit::diamonds:
        return CardColor::red;
    }
    assert(false);
    return CardColor::red;
}

auto operator<<(std::ostream& o, Suit suit) -> std::ostream& {
    ansi_color::printer const _ { o, ansi_color_for(color(suit)) };

    switch (suit) {
    case Suit::spades:
        o << "♠";
        break;
    case Suit::hearts:
        o << "♥";
        break;
    case Suit::diamonds:
        o << "♦";
        break;
    case Suit::clubs:
        o << "♣";
        break;
    }
    return o;
}

} // namespace ka