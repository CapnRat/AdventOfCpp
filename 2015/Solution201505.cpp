//
// Created by Shawn White on 2/2/22.
//

#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include "../Common.h"

SOLUTION(2015, 05, 1) {
    std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    std::unordered_map<char, char> combos{
            {'b', 'a'},
            {'d', 'c'},
            {'q', 'p'},
            {'y', 'x'}
    };


    std::stringstream input_stream(input, std::ios_base::in);
    std::string line;

    unsigned int nice_count = 0;
    while(std::getline(input_stream, line)) {
        unsigned int vowel_count = 0;
        bool has_double = false;
        bool has_combo = false;

        for (int i = 0; i < line.size(); i++) {
            auto letter = line[i];
            if (vowels.contains(letter))
                vowel_count++;

            if (i == 0)
                continue;

            auto prev = line[i - 1];
            if (letter == prev)
                has_double = true;

            if (combos.contains(letter) && combos[letter] == prev) {
                has_combo = true;
                break;
            }
        }

        if (!has_combo && has_double && vowel_count >= 3)
            nice_count++;
    }

    return std::to_string(nice_count);
}

#if TEST
#include "../SolutionTesting.h"

SOLUTION_TEST(2015, 05, 1, examples) {
    EXPECT_EQ("1", INVOKE_SOLUTION(2015, 05, 1, "ugknbfddgicrmopn"));
    EXPECT_EQ("1", INVOKE_SOLUTION(2015, 05, 1, "aaa"));
    EXPECT_EQ("0", INVOKE_SOLUTION(2015, 05, 1, "jchzalrnumimnmhp"));
    EXPECT_EQ("0", INVOKE_SOLUTION(2015, 05, 1, "haegwjzuvuyypxyu"));
    EXPECT_EQ("0", INVOKE_SOLUTION(2015, 05, 1, "dvszwmarrgswjxmb"));
}
#endif