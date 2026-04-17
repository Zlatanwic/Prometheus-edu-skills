// STAFF SOLUTION — state-machine CSV parser. O(n), single-pass, no regex.
// The three tricky cases: quoted commas, "" escapes, missing trailing \n.

#include "parser.hpp"
#include <sstream>

namespace csvstat {

static std::string fmt_line(std::size_t line, const std::string& msg) {
    std::ostringstream ss; ss << "line " << line << ": " << msg; return ss.str();
}

CsvFile parse(std::istream& in, bool has_header) {
    CsvFile out;
    std::vector<std::string> row;
    std::string field;
    enum { kField, kQuoted, kAfterQuote } state = kField;
    std::size_t line = 1;
    bool any_char_this_row = false;

    auto finish_row = [&]() {
        row.push_back(std::move(field));
        field.clear();
        if (out.header.empty() && has_header) {
            out.header = std::move(row);
        } else {
            out.rows.push_back(CsvRow{std::move(row)});
        }
        row.clear();
        any_char_this_row = false;
    };

    char c;
    while (in.get(c)) {
        if (state == kField) {
            if (c == ',') { row.push_back(std::move(field)); field.clear(); any_char_this_row = true; }
            else if (c == '\n') { if (any_char_this_row || !field.empty() || !row.empty()) finish_row(); ++line; }
            else if (c == '\r') { /* skip */ }
            else if (c == '"' && field.empty()) { state = kQuoted; any_char_this_row = true; }
            else { field.push_back(c); any_char_this_row = true; }
        } else if (state == kQuoted) {
            if (c == '"') state = kAfterQuote;
            else { if (c == '\n') ++line; field.push_back(c); }
        } else {  // kAfterQuote
            if (c == '"') { field.push_back('"'); state = kQuoted; }
            else if (c == ',') { row.push_back(std::move(field)); field.clear(); state = kField; }
            else if (c == '\n') { finish_row(); ++line; state = kField; }
            else if (c == '\r') { /* skip */ }
            else throw CsvError(fmt_line(line, "unexpected character after closing quote"));
        }
    }
    if (state == kQuoted) throw CsvError(fmt_line(line, "unterminated quoted field"));
    if (!field.empty() || !row.empty() || any_char_this_row) finish_row();

    // Validate column consistency.
    std::size_t expected = out.header.empty()
        ? (out.rows.empty() ? 0 : out.rows.front().fields.size())
        : out.header.size();
    for (std::size_t i = 0; i < out.rows.size(); ++i) {
        if (out.rows[i].fields.size() != expected)
            throw CsvError(fmt_line(i + (has_header ? 2 : 1),
                                    "wrong number of columns"));
    }
    return out;
}

}  // namespace csvstat
