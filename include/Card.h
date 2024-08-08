#ifndef KING_ALBERT_CPP_CARD_H
#define KING_ALBERT_CPP_CARD_H

#include <iosfwd>
#include <utility>

#include "Rank.h"
#include "Suit.h"

namespace ka {

class Card {
public:
    static constexpr auto const count = suit_count * Rank::count;
    Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit) {};
    [[nodiscard]] auto rank() const -> Rank {
        return m_rank;
    };
    [[nodiscard]] auto suit() const -> Suit {
        return m_suit;
    };
    [[nodiscard]] auto color() const -> CardColor {
        return ::ka::color(m_suit);
    };
    [[nodiscard]] auto is_ace() const -> bool {
        return m_rank.is_ace();
    };
    [[nodiscard]] auto is_king() const -> bool {
        return m_rank.is_king();
    };

private:
    Rank m_rank;
    Suit m_suit;
};

auto operator<<(std::ostream &o, Card card) -> std::ostream &;

} // namespace ka

#endif // KING_ALBERT_CPP_CARD_H
