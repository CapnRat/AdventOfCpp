//
// Created by shawn on 1/25/2022.
//


#include <string>
#include "../SolutionRegistry.h"

SOLUTION(2015, 01, 1) {
    int floor = 0;

    for(auto character : input) {
        if (character == '(')
            floor++;
        else
            floor--;
    }

    return std::to_string(floor);
}

SOLUTION(2015, 01, 2) {
    int floor = 0;

    for(int i = 0; i < input.size(); i++) {
        if (input[i] == '(')
            floor++;
        else
            floor--;

        if (floor == -1)
            return std::to_string(i + 1);
    }

    return "fail";
}
