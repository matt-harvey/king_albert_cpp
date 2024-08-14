#ifndef KING_ALBERT_CPP_INCLUDE_BOARD_H
#define KING_ALBERT_CPP_INCLUDE_BOARD_H

#include <iosfwd>
#include <optional>
#include <vector>

#include "ColumnPosition.h"
#include "Deck.h"
#include "FoundationPosition.h"
#include "HandPosition.h"
#include "Move.h"
#include "Position.h"
#include "Suit.h"

namespace ka {

class Board {
public:
    Board() = default;
    Board(Board const&) = delete;
    auto deal_from(Deck& shuffled_deck) -> void;
    [[nodiscard]] auto completed() const -> bool;
    [[nodiscard]] auto parse_move(char from_label, char to_label) -> std::optional<Move>;
    static auto execute_move(Move const&) -> bool;
    friend auto operator<<(std::ostream&, Board const&) -> std::ostream&;

private:
    /**
     * @returns a non-owning pointer to a position identified by the char, or nullptr if
     *   there is no such position.
     */
    [[nodiscard]] auto position_labelled(char) -> Position*;

    std::vector<FoundationPosition> m_foundations;
    std::vector<ColumnPosition> m_columns;
    std::vector<HandPosition> m_hand;
};

auto operator<<(std::ostream& o, Board const& board) -> std::ostream&;

} // namespace ka

#endif // KING_ALBERT_CPP_INCLUDE_BOARD_H
