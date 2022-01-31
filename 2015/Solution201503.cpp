//
// Created by Shawn White on 1/28/22.
//

#include <unordered_set>
#include <set>
#include "../SolutionRegistry.h"

struct point2 {
    int x, y;

    bool operator==(const point2& t) const
    {
        return (this->x == t.x && this->y == t.y);
    }
};

template<>
struct std::hash<point2> {
    std::size_t operator()(point2 const& i) const noexcept
    {
        std::size_t h1 = std::hash<int>{}(i.x);
        std::size_t h2 = std::hash<int>{}(i.y);
        return ((h1 << 5) + h1) ^ h2; // stolen from microsoft's hash combine in .net System.Numerics
    }
};

SOLUTION(2015, 03, 1) {
    point2 pos{0, 0};
    std::unordered_set<point2> visited{pos};

    for(auto character : input) {
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
        visited.insert(pos);
    }

    return std::to_string(visited.size());
}

#ifdef TEST
#include "../SolutionTesting.h"

SOLUTION_TEST(2015, 03, 1, examples) {
    EXPECT_EQ("2", INVOKE_SOLUTION(2015, 03, 1, ">"));
    EXPECT_EQ("4", INVOKE_SOLUTION(2015, 03, 1, "^>v<"));
    EXPECT_EQ("2", INVOKE_SOLUTION(2015, 03, 1, "^v^v^v^v^v"));
}
#endif