// TODO — summarize_column:
//   1. Classify the column as numeric (every non-empty cell parses as
//      double via std::from_chars) or text.
//   2. Populate NumericStats or TextStats accordingly.
// Empty strings are "missing".

#include "stats.hpp"
#include <stdexcept>

namespace csvstat {

ColumnStats summarize_column(const std::vector<std::string>& cells) {
    (void)cells;
    throw std::logic_error("UNIMPLEMENTED: summarize_column");
}

}  // namespace csvstat
