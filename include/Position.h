#ifndef KING_ALBERT_CPP_POSITION_H
#define KING_ALBERT_CPP_POSITION_H

#include "Card.h"
#include <optional>

namespace ka {

class Position {
public:
  virtual ~Position() = default;
  [[nodiscard]] virtual auto can_give() const -> bool = 0;
  [[nodiscard]] virtual auto next_card() const -> Card = 0;
  virtual auto give() -> Card = 0;
  [[nodiscard]] virtual auto can_receive(Card card) const -> bool = 0;
  virtual auto receive(Card card) -> void = 0;
};

} // ka

#endif // KING_ALBERT_CPP_POSITION_H
