//
// Created by shawn on 1/25/2022.
//

#include <string>
#include <sstream>
#include "../SolutionRegistry.h"

SOLUTION(2015, 02, 1) {
    std::stringstream input_stream(input, std::ios_base::in);
    std::string line;

    unsigned long accum = 0;

    while(std::getline(input_stream, line)) {
        std::size_t idx, idy;
        auto w = std::stoi(line, &idx, 10);
        auto l = std::stoi(line.substr(idx + 1), &idy, 10);
        auto h = std::stoi(line.substr(idx + idy + 2), nullptr, 10);

        auto wl = w * l;
        auto lh = l * h;
        auto hw = h * w;

        accum += 2 * (wl + lh + hw) + std::min({wl, lh, hw});
    }

    return std::to_string(accum);
}

#if TEST
#include "../SolutionTesting.h"

SOLUTION_TEST(2015, 02, 1, examples) {
    EXPECT_EQ("58", INVOKE_SOLUTION(2015, 02, 1, "2x3x4"));
    EXPECT_EQ("43", INVOKE_SOLUTION(2015, 02, 1, "1x1x10"));
    EXPECT_EQ("20", INVOKE_SOLUTION(2015, 02, 1, "0x1x10"));
    EXPECT_EQ("700", INVOKE_SOLUTION(2015, 02, 1, "10x10x10"));
    EXPECT_EQ("101", INVOKE_SOLUTION(2015, 02, 1, "2x3x4\n1x1x10"));
}
#endif