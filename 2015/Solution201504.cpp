//
// Created by shawn on 1/31/2022.
//

#include <openssl/md5.h>
#include <sstream>
#include <cstring>
#include "../Common.h"

SOLUTION(2015, 04, 1) {
    unsigned char buffer[MD5_DIGEST_LENGTH];

    for(int i = 0;; i++) {
        std::string test(input + std::to_string(i));
        MD5((unsigned char *) test.c_str(), test.size(), buffer);

        if (buffer[0] == 0 && buffer[1] == 0 && buffer[2] < 0x10) return std::to_string(i);
    }
}

SOLUTION(2015, 04, 2) {
    unsigned char buffer[MD5_DIGEST_LENGTH];
    char testc_str[input.size() + 10]; // 10 max digits in an unsigned long, assume solution isn't larger than that
    strncpy(testc_str, input.c_str(), input.size());

    int next_increase = 10;
    int num_digits = 1;
    for(int i = 0;; i++) {

        // avoiding the string concatenation every iteration, saves ~50ms, with total time ~330ms. (On my machine)
        if (i == next_increase) {
            num_digits++;
            next_increase *= 10;
        }
        for(int d = i, n = num_digits - 1; n >= 0; d /= 10, n--) {
            testc_str[input.size() + n] = (char)(d % 10 + 48);
        }

        MD5((unsigned char *) testc_str, input.size() + num_digits, buffer);

        if (buffer[0] == 0 && buffer[1] == 0 && buffer[2] == 0) return std::to_string(i);
    }
}

#ifdef TEST
#include "../SolutionTesting.h"

SOLUTION_TEST(2015, 04, 1, examples) {
    EXPECT_EQ("609043", INVOKE_SOLUTION(2015, 04, 1, "abcdef"));
    EXPECT_EQ("1048970", INVOKE_SOLUTION(2015, 04, 1, "pqrstuv"));
}
#endif