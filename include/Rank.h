#ifndef KING_ALBERT_CPP_RANK_H
#define KING_ALBERT_CPP_RANK_H

#include <iosfwd>

namespace ka {

class Rank {
public:
  static constexpr auto const max_value { 13 };
  static constexpr auto const min_value { 1 };
  static constexpr auto const count = max_value - min_value + 1;

  explicit Rank(int value);

  [[nodiscard]] auto follows(Rank other) const -> bool;
  [[nodiscard]] auto precedes(Rank other) const -> bool;
  [[nodiscard]] auto is_ace() const -> bool { return m_value == min_value; };
  [[nodiscard]] auto is_king() const -> bool { return m_value == max_value; };
  friend auto operator<<(std::ostream&, Rank rank) -> std::ostream&;
private:
  int m_value;
};

auto operator<<(std::ostream& o, Rank rank) -> std::ostream&;

}

#endif // KING_ALBERT_CPP_RANK_H
