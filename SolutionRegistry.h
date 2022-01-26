//
// Created by shawn on 1/25/2022.
//

#ifndef ADVENTOFCPP_SOLUTIONREGISTRY_H
#define ADVENTOFCPP_SOLUTIONREGISTRY_H

#include <string>
#include <functional>
#include <map>

#define SOLUTION(Year, Day, Star) \
    std::string Solution##Year##Day##Star(const std::string&); \
    static bool solution_##Year##Day##Star##_registered = SolutionRegistry::Register(Year, Day, Star, &Solution##Year##Day##Star); \
    std::string Solution##Year##Day##Star(const std::string& input)

typedef std::function<std::string(const std::string&)> SolutionFunc;
typedef std::map<unsigned int, SolutionFunc> SolutionsMap;
typedef unsigned int uint;

class SolutionRegistry {
private:
    static SolutionsMap& Solutions();

public:
    static const SolutionsMap& GetSolutions();

    static bool Register(uint year, uint day, uint star, SolutionFunc func);
};


#endif //ADVENTOFCPP_SOLUTIONREGISTRY_H
