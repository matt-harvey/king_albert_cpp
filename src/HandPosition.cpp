#include "HandPosition.h"

#include <iostream>

namespace ka {

auto HandPosition::can_give() const -> bool {
    return m_card.has_value();
}

auto HandPosition::next_card() const -> Card {
    return m_card.value();
}

auto HandPosition::give() -> Card {
    auto const card { m_card.value() };
    m_card = std::nullopt;
    return card;
}

auto HandPosition::can_receive(Card card) const -> bool {
    return false;
}

auto HandPosition::receive(Card card) -> void {
    ; // noop
}

auto operator<<(std::ostream &o, HandPosition const &h) -> std::ostream & {
    if (h.m_card.has_value()) {
        o << h.m_card.value();
    } else {
        o << "   ";
    }
    return o;
}

} // namespace ka
