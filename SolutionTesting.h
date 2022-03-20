//
// Created by shawn on 1/26/2022.
//

#ifndef ADVENTOFCPP_SOLUTIONTESTING_H
#define ADVENTOFCPP_SOLUTIONTESTING_H

#include <gtest/gtest.h>
#include "Common.h"

#define SOLUTION_ANSWER(year, day, star, answer) \
std::string Solution##year##day##star(const std::string&); \
TEST(SolutionTests_##year##day##star, Answer) { \
    EXPECT_EQ(answer, Solution##year##day##star(get_input(year##day##star))); \
}
#define SOLUTION_TEST(year, day, star, test_name) TEST(SolutionTests_##year##day##star, test_name)
#define INVOKE_SOLUTION(year, day, star, input) Solution##year##day##star(input)

#endif //ADVENTOFCPP_SOLUTIONTESTING_H
