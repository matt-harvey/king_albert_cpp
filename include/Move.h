#ifndef KA_INCLUDE_MOVE_H
#define KA_INCLUDE_MOVE_H

#include "Position.h"

namespace ka {

struct Move {
    Position& from;
    Position& to;
};

} // ka

#endif //KA_INCLUDE_MOVE_H
