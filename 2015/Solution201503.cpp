//
// Created by Shawn White on 1/28/22.
//

#include <unordered_set>
#include <set>
#include "../Common.h"
#include "../SolutionTesting.h"

struct point2 {
    int x, y;

    bool operator==(const point2& t) const {
        return (this->x == t.x && this->y == t.y);
    }
};

template<>
struct std::hash<point2> {
    std::size_t operator()(const point2& i) const noexcept {
        std::size_t h1 = std::hash<int>{}(i.x);
        std::size_t h2 = std::hash<int>{}(i.y);
        return ((h1 << 5) + h1) ^ h2; // stolen from microsoft's hash combine in .net System.Numerics
    }
};

void move(point2& pos, const char& character) {
    switch (character) {
        case '^':
            pos.y++; break;
        case 'v':
            pos.y--; break;
        case '>':
            pos.x++; break;
        case '<':
            pos.x--; break;
        default:
            throw std::runtime_error(std::string("Unexpected character: ") + character);
    }
}

SOLUTION(2015, 03, 1) {
    point2 pos{0, 0};
    std::unordered_set<point2> visited{pos};

    for(auto character : input) {
        move(pos, character);
        visited.insert(pos);
    }

    return std::to_string(visited.size());
}

SOLUTION(2015, 03, 2) {
    point2 santa{0, 0};
    point2 robot{0, 0};
    std::unordered_set<point2> visited{santa};

    for(int i = 0; i < input.size(); i++)
    {
        point2& current = i % 2 == 0 ? santa : robot;
        move(current, input[i]);
        visited.insert(current);
    }

    return std::to_string(visited.size());
}

SOLUTION_TEST(2015, 03, 1, examples) {
    EXPECT_EQ("2", INVOKE_SOLUTION(2015, 03, 1, ">"));
    EXPECT_EQ("4", INVOKE_SOLUTION(2015, 03, 1, "^>v<"));
    EXPECT_EQ("2", INVOKE_SOLUTION(2015, 03, 1, "^v^v^v^v^v"));
}

SOLUTION_TEST(2015, 03, 2, examples) {
    EXPECT_EQ("3", INVOKE_SOLUTION(2015, 03, 2, "^v"));
    EXPECT_EQ("3", INVOKE_SOLUTION(2015, 03, 2, "^>v<"));
    EXPECT_EQ("11", INVOKE_SOLUTION(2015, 03, 2, "^v^v^v^v^v"));
}