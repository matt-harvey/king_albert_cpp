#include <iostream>
#include <random>

#include "../include/Game.h"

auto main() -> int {
    auto random_device { std::random_device() };
    auto game { ka::Game {} };
    game.prepare(random_device);
    game.play(std::cout, std::cin);
    return 0;
}
