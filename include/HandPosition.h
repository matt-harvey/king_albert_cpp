#ifndef KING_ALBERT_CPP__HAND_POSITION_H
#define KING_ALBERT_CPP__HAND_POSITION_H

#include <iosfwd>
#include <optional>

#include "Card.h"
#include "Position.h"

namespace ka {

class HandPosition : public Position {
public:
    explicit HandPosition(Card card) : m_card { card } {};

    [[nodiscard]] auto can_give() const -> bool override;
    [[nodiscard]] auto next_card() const -> Card override;
    auto give() -> Card override;
    [[nodiscard]] auto can_receive(Card card) const -> bool override;
    auto receive(Card card) -> void override;

    friend auto operator<<(std::ostream &, HandPosition const &) -> std::ostream &;

private:
    std::optional<Card> m_card;
};

} // namespace ka

#endif // KING_ALBERT_CPP__HAND_POSITION_H
