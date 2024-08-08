#ifndef KING_ALBERT_CPP_INCLUDE_GAME_H
#define KING_ALBERT_CPP_INCLUDE_GAME_H

#include <iosfwd>
#include <memory>
#include <random>

#include "Board.h"
#include "Deck.h"
#include "GameState.h"

namespace ka {

class Game {
public:
    Game() : m_board { std::make_unique<Board>() }, m_game_state { GameState::unprepared } {};
    Game(Game const&) = delete;
    auto prepare(std::random_device&) -> void;
    auto play(std::ostream& out, std::istream& in) -> void;

private:
    auto set_game_state(GameState game_state) -> void {
        m_game_state = game_state;
    };
    auto consume_move(std::ostream& out, std::istream& in) -> void;
    std::unique_ptr<Board> m_board;
    GameState m_game_state;
};

} // namespace ka

#endif // KING_ALBERT_CPP_INCLUDE_GAME_H
