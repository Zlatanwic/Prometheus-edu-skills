// TODO — implement CSV parser per README §4. Handle quoted fields,
// "" escapes, CRLF, files without trailing newline. Throw CsvError on
// malformed input, including a 1-based line number.

#include "parser.hpp"
#include <sstream>

namespace csvstat {

CsvFile parse(std::istream& in, bool has_header) {
    (void)in; (void)has_header;
    throw std::logic_error("UNIMPLEMENTED: parse");
}

}  // namespace csvstat
