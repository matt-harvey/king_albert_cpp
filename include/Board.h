#ifndef KING_ALBERT_CPP_INCLUDE_BOARD_H
#define KING_ALBERT_CPP_INCLUDE_BOARD_H

#include <iosfwd>
#include <optional>
#include <vector>
#include <memory>
#include "Deck.h"
#include "FoundationPosition.h"
#include "ColumnPosition.h"
#include "HandPosition.h"
#include "Position.h"
#include "Suit.h"

namespace ka {

class Board {
public:
  /** A pair of non-owning, non-null pointers to existing Positions on the board */
  typedef std::pair<std::shared_ptr<Position>, std::shared_ptr<Position>> Move;

  Board() = default;
  Board(Board const&) = delete;
  auto deal_from(Deck& shuffled_deck) -> void;
  [[nodiscard]] auto completed() const -> bool;
  [[nodiscard]] auto parse_move(char from_label, char to_label) -> std::optional<Move>;
  static auto execute_move(Move const&) -> bool;
  friend auto operator<<(std::ostream&, Board const&) -> std::ostream&;
private:
  [[nodiscard]] auto position_labelled(char) -> std::shared_ptr<Position>;
  std::vector<std::shared_ptr<FoundationPosition>> m_foundations;
  std::vector<std::shared_ptr<ColumnPosition>> m_columns;
  std::vector<std::shared_ptr<HandPosition>> m_hand;
};

auto operator<<(std::ostream& o, Board const& board) -> std::ostream&;

} // ka

#endif //KING_ALBERT_CPP_INCLUDE_BOARD_H
