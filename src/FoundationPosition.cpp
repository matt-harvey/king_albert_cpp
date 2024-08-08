#include "FoundationPosition.h"

#include <iostream>
#include <optional>

namespace ka {

FoundationPosition::FoundationPosition(Suit suit) : m_suit { suit }, m_rank { std::nullopt } {
}

auto FoundationPosition::can_give() const -> bool {
    return false;
}

auto FoundationPosition::next_card() const -> Card {
    return Card { m_rank.value(), m_suit };
}

auto FoundationPosition::give() -> Card {
    throw std::runtime_error("Intentionally unimplemented");
}

auto FoundationPosition::can_receive(Card card) const -> bool {
    if (card.suit() != m_suit) {
        return false;
    }
    if (!m_rank.has_value()) {
        return card.is_ace();
    }
    return card.rank().follows(m_rank.value());
}

auto FoundationPosition::receive(Card card) -> void {
    m_rank = card.rank();
}

auto FoundationPosition::completed() const -> bool {
    return m_rank.has_value() && m_rank.value().is_king();
}

auto operator<<(std::ostream& o, FoundationPosition const& f) -> std::ostream& {
    ansi_color::printer const _ { o, ansi_color_for(color(f.m_suit)) };
    if (f.m_rank.has_value()) {
        o << f.m_rank.value();
    } else {
        o << "  ";
    }
    o << f.m_suit;
    return o;
}

} // namespace ka
