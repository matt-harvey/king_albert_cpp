#include "../include/Rank.h"

#include <ostream>
#include <stdexcept>
#include <utility>

namespace ka {

Rank::Rank(int value) : m_value(value) {
    if (value < min_value || value > max_value) {
        throw std::runtime_error("Rank value invalid");
    }
}

auto Rank::follows(Rank other) const -> bool {
    return m_value == other.m_value + 1;
}

auto Rank::precedes(Rank other) const -> bool {
    return other.follows(*this);
}

auto operator<<(std::ostream &o, Rank rank) -> std::ostream & {
    auto const value { rank.m_value };
    switch (value) {
    case 1:
        o << " A";
        break;
    case 10:
        o << "10";
        break;
    case 11:
        o << " J";
        break;
    case 12:
        o << " Q";
        break;
    case 13:
        o << " K";
        break;
    default:
        o << ' ' << value;
        break;
    }
    return o;
}

} // namespace ka