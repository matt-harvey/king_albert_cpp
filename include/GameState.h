#ifndef KING_ALBERT_CPP_INCLUDE_GAMESTATE_H
#define KING_ALBERT_CPP_INCLUDE_GAMESTATE_H

namespace ka {

enum class GameState {
    unprepared,
    prepared,
    playing,
    won,
    quit,
};

} // namespace ka

#endif // KING_ALBERT_CPP_INCLUDE_GAMESTATE_H
