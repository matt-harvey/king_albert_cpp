#include "../include/ColumnPosition.h"

namespace ka {

auto ColumnPosition::card_at(ColumnPosition::size_type i) const -> Card {
    return m_cards[i];
}

auto ColumnPosition::can_give() const -> bool {
    return !m_cards.empty();
}

auto ColumnPosition::next_card() const -> Card {
    return m_cards.back();
}

auto ColumnPosition::give() -> Card {
    auto card { m_cards.back() };
    m_cards.pop_back();
    return card;
}

auto ColumnPosition::can_receive(Card card) const -> bool {
    if (m_cards.empty()) {
        return true;
    }
    auto const top_card { m_cards.back() };
    if (card.color() == top_card.color()) {
        return false;
    }
    return card.rank().precedes(top_card.rank());
}

auto ColumnPosition::receive(Card card) -> void {
    m_cards.push_back(card);
}

} // namespace ka