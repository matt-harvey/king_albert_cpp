#ifndef KING_ALBERT_CPP__HANDPOSITION_H
#define KING_ALBERT_CPP__HANDPOSITION_H

#include "Position.h"
#include "Card.h"
#include <optional>
#include <iosfwd>

namespace ka {

class HandPosition: public Position {
public:
  explicit HandPosition(Card card): m_card { card } {};

  [[nodiscard]] auto can_give() const -> bool override;
  [[nodiscard]] auto next_card() const -> Card;
  auto give() -> Card override;
  [[nodiscard]] auto can_receive(Card card) const -> bool override;
  auto receive(Card card) -> void override;

  friend auto operator<<(std::ostream&, HandPosition const&) -> std::ostream&;
private:
  std::optional<Card> m_card;
};

} // ka

#endif //KING_ALBERT_CPP__HANDPOSITION_H
