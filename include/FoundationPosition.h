#ifndef KING_ALBERT_CPP_FOUNDATION_POSITION_H
#define KING_ALBERT_CPP_FOUNDATION_POSITION_H

#include "Position.h"
#include "Suit.h"
#include <iosfwd>
#include <optional>

namespace ka {

class FoundationPosition: public Position {
public:
  explicit FoundationPosition(Suit suit);

  [[nodiscard]] auto can_give() const -> bool override;
  [[nodiscard]] auto next_card() const -> Card;
  auto give() -> Card override;
  [[nodiscard]] auto can_receive(Card card) const -> bool override;
  auto receive(Card card) -> void override;

  [[nodiscard]] auto completed() const -> bool;
  friend auto operator<<(std::ostream&, FoundationPosition const&) -> std::ostream&;
private:
  Suit m_suit;
  std::optional<Rank> m_rank;
};

} // ka

#endif // KING_ALBERT_CPP_FOUNDATION_POSITION_H
