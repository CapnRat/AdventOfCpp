//
// Created by shawn on 1/25/2022.
//

#include "SolutionRegistry.h"

#include <utility>

uint GetID(uint year, uint day, uint star)
{
    // Format: YYDDS
    return year * 1000 + day * 10 + star;
}

bool SolutionRegistry::Register(uint year, uint day, uint star, SolutionFunc func) {
    auto id = GetID(year, day, star);
    if (!Solutions().contains(id)) {
        Solutions()[id] = std::move(func);
        return true;
    }
    return false;
}

SolutionsMap &SolutionRegistry::Solutions() {
    static SolutionsMap Solutions;
    return Solutions;
}

const SolutionsMap &SolutionRegistry::GetSolutions() {
    return Solutions();
}
