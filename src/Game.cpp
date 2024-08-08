#include "Game.h"

#include <cassert>
#include <iostream>
#include <jewel/log.hpp>
#include <string>

namespace ka {

auto Game::prepare(std::random_device &random_device) -> void {
    auto deck { Deck {} };
    deck.shuffle(random_device);
    m_board->deal_from(deck);
    m_game_state = GameState::prepared;
}

auto Game::play(std::ostream &out, std::istream &in) -> void {
    m_game_state = GameState::playing;

    while (true) {
        out << *m_board;
        consume_move(out, in);

        switch (m_game_state) {
        case GameState::playing:
            break;
        case GameState::quit:
            out << std::endl << "Thanks for playing. Goodbye!" << std::endl;
            return;
        case GameState::won:
            out << std::endl << "You won. Congratulations!" << std::endl;
            return;
        default:
            assert(false);
        }
    }
}

auto Game::consume_move(std::ostream &out, std::istream &in) -> void {
    ansi_color::printer const _ { out, ansi_color::green };

    while (true) {
        out << std::endl << "Enter your move: ";
        std::string input {};
        {
            ansi_color::printer const _ { out, ansi_color::blue };
            in >> input;
        }
        if (input == "quit" || input == "exit") {
            set_game_state(GameState::quit);
            return;
        }
        if (input.length() != 2) {
            out << "This move is invalid. Please enter two letters, the 'from' "
                   "position, followed by the 'to' position."
                << std::endl;
            continue;
        }
        auto const from_label { input[0] };
        auto const to_label { input[1] };
        auto const maybe_move { m_board->parse_move(from_label, to_label) };
        if (!maybe_move.has_value()) {
            out << "This move is illegal." << std::endl;
            continue;
        }
        if (!m_board->execute_move(maybe_move.value())) {
            out << "This move is not allowed." << std::endl;
            continue;
        }
        if (m_board->completed()) {
            set_game_state(GameState::won);
            return;
        }
        return;
    }
}

} // namespace ka