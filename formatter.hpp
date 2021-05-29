#pragma once
#ifndef FORMATOR_H_
#define FORMATOR_H_

#include <fmt/format.h>
#include "HashMap.hpp"

namespace sy
{
    struct point { double x, y; };

    template <typename K>
    struct pointer { double x, y; };
}

template <>
struct fmt::formatter<sy::point> {
    // Presentation format: 'f' - fixed, 'e' - exponential.
    char presentation = 'f';

    // Parses format specifications of the form ['f' | 'e'].
    constexpr auto parse(fmt::format_parse_context& ctx) {
        // auto parse(format_parse_context &ctx) -> decltype(ctx.begin()) // c++11
          // [ctx.begin(), ctx.end()) is a character range that contains a part of
          // the format string starting from the format specifications to be parsed,
          // e.g. in
          //
          //   fmt::format("{:f} - point of interest", point{1, 2});
          //
          // the range will contain "f} - point of interest". The formatter should
          // parse specifiers until '}' or the end of the range. In this example
          // the formatter should parse the 'f' specifier and return an iterator
          // pointing to '}'.

          // Parse the presentation format and store it in the formatter:
        auto it = ctx.begin(), end = ctx.end();
        if (it != end && (*it == 'f' || *it == 'e')) presentation = *it++;

        // Check if reached the end of the range:
        if (it != end && *it != '}')
            throw fmt::format_error("invalid format");

        // Return an iterator past the end of the parsed range:
        return it;
    }

    // Formats the point p using the parsed format specification (presentation)
    // stored in this formatter.
    template <typename FormatContext>
    auto format(const sy::point& p, FormatContext& ctx) {
        // auto format(const point &p, FormatContext &ctx) -> decltype(ctx.out()) // c++11
        // ctx.out() is an output iterator to write to.
        return format_to(
            ctx.out(),
            presentation == 'f' ? "({:.1f}, {:.1f})" : "({:.1e}, {:.1e})",
            p.x, p.y);
    }
};

template <typename K>
struct fmt::formatter<sy::pointer<K> > : formatter<string_view> {
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(const sy::pointer<K>& p, FormatContext& ctx) {
        auto s = fmt::format("({}, {})", p.x, p.y);
        return formatter<string_view>::format(s, ctx);
    }
};

template <typename K, typename V>
struct fmt::formatter<pair<K, V> > : formatter<string_view> {
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(const pair<K, V>& p, FormatContext& ctx) {
        auto s = fmt::format("({}, {})", p.first, p.second);
        return formatter<string_view>::format(s, ctx);
    }
};

template <typename E>
struct fmt::formatter<vector<E> > : formatter<string_view> {
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(const vector<E>& vec, FormatContext& ctx) {
        basic_string<char> s;
        for (const auto& i : vec) {
            s += fmt::format("{:<3} ", i);
        }
        s += fmt::format("\n");
        return formatter<string_view>::format(s, ctx);
    }
};

#endif

