//
// Created by shawn on 1/26/2022.
//

#ifndef ADVENTOFCPP_SOLUTIONTESTING_H
#define ADVENTOFCPP_SOLUTIONTESTING_H

#include <gtest/gtest.h>

#define SOLUTION_TEST(year, day, star, test_name) TEST(SolutionTests_##year##day##star, test_name)
#define INVOKE_SOLUTION(year, day, star, input) Solution##year##day##star(input)

#endif //ADVENTOFCPP_SOLUTIONTESTING_H
