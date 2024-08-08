#ifndef KING_ALBERT_CPP_SUIT_H
#define KING_ALBERT_CPP_SUIT_H

#include <array>
#include <iosfwd>

#include "CardColor.h"

namespace ka {

enum class Suit {
    spades,
    hearts,
    diamonds,
    clubs
};

auto constexpr all_suits { std::array { Suit::spades, Suit::hearts, Suit::diamonds, Suit::clubs } };

constexpr auto const suit_count { all_suits.size() };

auto color(Suit suit) -> CardColor;

auto operator<<(std::ostream &o, Suit suit) -> std::ostream &;

} // namespace ka

#endif // KING_ALBERT_CPP_SUIT_H
