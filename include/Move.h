#ifndef KA_INCLUDE_MOVE_H
#define KA_INCLUDE_MOVE_H

#include "Position.h"

namespace ka {

struct Move {
    /** non-owning pointer to the position to be moved from */
    Position& from;

    /** non-owning pointer to the position to be moved to */
    Position& to;
};

} // ka

#endif //KA_INCLUDE_MOVE_H
