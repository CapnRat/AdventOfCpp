//
// Created by shawn on 1/25/2022.
//

#include <string>
#include <sstream>
#include "../SolutionRegistry.h"

typedef std::tuple <int, int, int> dimensions;

dimensions get_dimensions(const std::string& line) {
    std::size_t idx, idy;
    auto w = std::stoi(line, &idx, 10);
    auto l = std::stoi(line.substr(idx + 1), &idy, 10);
    auto h = std::stoi(line.substr(idx + idy + 2), nullptr, 10);

    return std::make_tuple(w, l, h);
}

SOLUTION(2015, 02, 1) {
    std::stringstream input_stream(input, std::ios_base::in);
    std::string line;

    unsigned long accum = 0;

    while(std::getline(input_stream, line)) {
        auto dimensions = get_dimensions(line);

        auto wl = std::get<0>(dimensions) * std::get<1>(dimensions);
        auto lh = std::get<1>(dimensions) * std::get<2>(dimensions);
        auto hw = std::get<0>(dimensions) * std::get<2>(dimensions);

        accum += 2 * (wl + lh + hw) + std::min({wl, lh, hw});
    }

    return std::to_string(accum);
}

SOLUTION(2015, 02, 2) {
    std::stringstream input_stream(input, std::ios_base::in);
    std::string line;

    unsigned long accum = 0;

    while(std::getline(input_stream, line)) {
        auto dimensions = get_dimensions(line);

        auto w = std::get<0>(dimensions);
        auto l = std::get<1>(dimensions);
        auto h = std::get<2>(dimensions);

        accum += 2 * ((w + l + h) - std::max({w, l, h})) + (l * w * h);
    }

    return std::to_string(accum);
}

#if TEST
#include "../SolutionTesting.h"

TEST(GetDimensionsTests, CanParseDimensions) {
    EXPECT_EQ(std::make_tuple(2, 3, 4), get_dimensions("2x3x4"));
    EXPECT_EQ(std::make_tuple(1, 1, 10), get_dimensions("1x1x10"));
}

SOLUTION_TEST(2015, 02, 1, examples) {
    EXPECT_EQ("58", INVOKE_SOLUTION(2015, 02, 1, "2x3x4"));
    EXPECT_EQ("43", INVOKE_SOLUTION(2015, 02, 1, "1x1x10"));
    EXPECT_EQ("20", INVOKE_SOLUTION(2015, 02, 1, "0x1x10"));
    EXPECT_EQ("700", INVOKE_SOLUTION(2015, 02, 1, "10x10x10"));
    EXPECT_EQ("101", INVOKE_SOLUTION(2015, 02, 1, "2x3x4\n1x1x10"));
}

SOLUTION_TEST(2015, 02, 2, examples) {
    EXPECT_EQ("34", INVOKE_SOLUTION(2015, 02, 2, "2x3x4"));
    EXPECT_EQ("14", INVOKE_SOLUTION(2015, 02, 2, "1x1x10"));
    EXPECT_EQ("48", INVOKE_SOLUTION(2015, 02, 2, "2x3x4\n1x1x10"));
}
#endif