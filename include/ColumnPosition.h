#ifndef KING_ALBERT_CPP_COLUMN_POSITION_H
#define KING_ALBERT_CPP_COLUMN_POSITION_H

#include <vector>

#include "Position.h"

namespace ka {

class ColumnPosition : public Position {
public:
    typedef std::vector<Card>::size_type size_type;
    [[nodiscard]] auto card_at(size_type i) const -> Card;

    [[nodiscard]] auto can_give() const -> bool override;
    [[nodiscard]] auto next_card() const -> Card override;
    auto give() -> Card override;
    [[nodiscard]] auto can_receive(Card card) const -> bool override;
    auto receive(Card card) -> void override;

    [[nodiscard]] auto size() const -> size_type {
        return m_cards.size();
    };

private:
    std::vector<Card> m_cards;
};

} // namespace ka

#endif // KING_ALBERT_CPP_COLUMN_POSITION_H
