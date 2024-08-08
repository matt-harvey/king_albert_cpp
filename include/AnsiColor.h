#ifndef KA_INCLUDE_ANSI_COLOR_H
#define KA_INCLUDE_ANSI_COLOR_H

#include <iostream>
#include <string>
#include <utility>

namespace ka {

namespace ansi_color {
auto constexpr black { "\033[30m" };
auto constexpr red { "\033[31m" };
auto constexpr blue { "\033[34m" };
auto constexpr green { "\033[32m" };
auto constexpr reset { "\033[0m" };

struct printer {
    printer(std::ostream &os, std::string const &format) : os { os } {
        os << format;
    }
    ~printer() {
        os << reset;
    }
    std::ostream &os;
};
}; // namespace ansi_color

} // namespace ka

#endif // KA_INCLUDE_ANSI_COLOR_H
