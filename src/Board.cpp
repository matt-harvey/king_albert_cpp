#include "Board.h"

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <optional>

namespace ka {

namespace {
auto const clear_screen { "\033[2J\033[H" };
}

auto Board::deal_from(Deck& shuffled_deck) -> void {
    m_foundations.emplace_back(Suit::spades);
    m_foundations.emplace_back(Suit::hearts);
    m_foundations.emplace_back(Suit::diamonds);
    m_foundations.emplace_back(Suit::clubs);

    for (auto column_index { 0 }; column_index != 9; ++column_index) {
        m_columns.emplace_back();
        for (auto dealt_to_column { 0 }; dealt_to_column != column_index + 1; ++dealt_to_column) {
            m_columns[column_index].receive(shuffled_deck.deal());
        }
    }
    assert(m_columns[0].size() == 1);
    assert(m_columns[8].size() == 9);

    while (!shuffled_deck.empty()) {
        m_hand.emplace_back(shuffled_deck.deal());
    }
    assert(m_hand.size() == 7);
}

auto Board::completed() const -> bool {
    if (m_foundations.size() != suit_count) {
        return false;
    }
    return std::ranges::all_of(m_foundations, std::mem_fn(&FoundationPosition::completed));
}

auto Board::parse_move(char from_label, char to_label) -> std::optional<Move> {
    auto from_position = position_labelled(from_label);
    if (from_position == nullptr) {
        return std::nullopt;
    }
    auto to_position = position_labelled(to_label);
    if (to_position == nullptr) {
        return std::nullopt;
    }
    return { Move { *from_position, *to_position } };
}

auto Board::execute_move(Move const& move) -> bool {
    if (!move.from.can_give()) {
        return false;
    }
    auto const card { move.from.next_card() };
    if (!move.to.can_receive(card)) {
        return false;
    }
    move.to.receive(move.from.give());
    return true;
}

auto Board::position_labelled(char label) -> Position* {
    switch (label) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
        return &(m_foundations[label - 'a']);
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
        return &(m_columns[label - 'e']);
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
        return &(m_hand[label - 'n']);
    default:
        return nullptr;
    }
}

auto operator<<(std::ostream& o, Board const& board) -> std::ostream& {
    o << clear_screen << std::endl;

    // Print foundations
    {
        ansi_color::printer const _ { o, ansi_color::blue };
        o << "                    [a] [b] [c] [d]" << std::endl << std::endl << "                   ";
    }
    for (auto const& foundation : board.m_foundations) {
        o << ' ' << foundation;
    }
    o << std::endl << std::endl << std::endl;

    // Print columns
    {
        ansi_color::printer const _ { o, ansi_color::blue };
        o << "[e] [f] [g] [h] [i] [j] [k] [l] [m]" << std::endl << std::endl;
    }
    auto num_columns_output { 0 };
    for (auto i { 0 };; ++i) {
        for (auto const& column : board.m_columns) {
            if (i < column.size()) {
                o << column.card_at(i) << ' ';
                ++num_columns_output;
            } else {
                o << "    ";
            }
        }
        if (num_columns_output == 0) {
            break;
        }
        o << std::endl;
        num_columns_output = 0;
    }
    o << std::endl;

    // Print hand
    {
        ansi_color::printer const _ { o, ansi_color::blue };
        o << "[n] [o] [p] [q] [r] [s] [t]" << std::endl << std::endl;
    }
    for (auto const& hp : board.m_hand) {
        o << hp << ' ';
    }
    o << std::endl;

    return o;
}

} // namespace ka
