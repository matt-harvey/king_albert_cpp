#ifndef KING_ALBERT_CPP_INCLUDE_DECK_H
#define KING_ALBERT_CPP_INCLUDE_DECK_H

#include <random>
#include <vector>

#include "Card.h"

namespace ka {

class Deck {
public:
    Deck();
    auto deal() -> Card;
    auto shuffle(std::random_device &) -> void;
    [[nodiscard]] auto empty() const -> bool;

private:
    typedef std::vector<Card> container_type;
    typedef container_type::size_type size_type;

public:
    [[nodiscard]] static constexpr auto size() -> size_type {
        return Card::count;
    };

private:
    container_type m_cards;
};

} // namespace ka

#endif // KING_ALBERT_CPP_INCLUDE_DECK_H
