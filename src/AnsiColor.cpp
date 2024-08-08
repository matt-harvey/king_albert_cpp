#include "AnsiColor.h"

#include <iostream>

namespace ka {

namespace ansi_color {

printer::printer(std::ostream& os, std::string const& format) : m_os { os } {
    m_os << format;
}
printer::~printer() {
    m_os << reset;
}

} // namespace ansi_color

} // namespace ka