//
// Created by Shawn White on 3/2/22.
//

#include "../Common.h"
#include "../SolutionTesting.h"

using LightPos = std::pair<unsigned short, unsigned short>;

enum Operation {
    Off = 0,
    On = 1,
    Toggle = 2
};

struct Instruction {
    Instruction(LightPos start, LightPos end, Operation op) :
        start(std::move(start)), end(std::move(end)), op(op) {}

    Instruction() :
        start(std::pair(0, 0)), end(std::pair(0, 0)), op(Operation::Off) {}

    bool operator==(const Instruction &rhs) const {
        return start == rhs.start &&
               end == rhs.end &&
               op == rhs.op;
    }

    bool operator!=(const Instruction &rhs) const {
        return !(rhs == *this);
    }

    LightPos start, end;
    Operation op;
};

Instruction getInstruction (const std::string& line) {
    Instruction in;

    std::string toggle;
    std::istringstream line_stream(line);
    line_stream >> toggle;
    if (toggle == "turn") {
        line_stream >> toggle;
        if (toggle == "on") {
            in.op = Operation::On;
        } else {
            in.op = Operation::Off;
        }
    }
    else {
        in.op = Operation::Toggle;
    }

    char cIgnore;
    std::string sIgnore;
    line_stream >> in.start.first >> cIgnore >> in.start.second
                >> sIgnore >> in.end.first >> cIgnore >> in.end.second;

    return in;
}

SOLUTION(2015, 06, 1) {
    bool lights[1000][1000] = {};

    std::stringstream input_stream(input, std::ios_base::in);
    std::string line;
    while(std::getline(input_stream, line)) {
        auto in = getInstruction(line);

        for(int x = in.start.first; x <= in.end.first; x++) {
            for(int y = in.start.second; y <= in.end.second; y++) {
                switch (in.op) {
                    case Off:
                        lights[x][y] = false;
                        break;
                    case On:
                        lights[x][y] = true;
                        break;
                    case Toggle:
                        lights[x][y] = !lights[x][y];
                        break;
                }
            }
        }
    }

    return std::to_string(std::count(*lights, *lights + sizeof(lights), true));
}

SOLUTION(2015, 06, 2) {
    unsigned int lights[1000][1000] = {};

    std::stringstream input_stream(input, std::ios_base::in);
    std::string line;
    while(std::getline(input_stream, line)) {
        auto in = getInstruction(line);

        for(int x = in.start.first; x <= in.end.first; x++) {
            for(int y = in.start.second; y <= in.end.second; y++) {
                switch (in.op) {
                    case Off:
                        if (lights[x][y] > 0)
                            lights[x][y]--;
                        break;
                    case On:
                        lights[x][y]++;
                        break;
                    case Toggle:
                        lights[x][y] += 2;
                        break;
                }
            }
        }
    }

    unsigned int brightness = 0;
    for(int i = 0; i < (sizeof(lights) / sizeof(unsigned int)); i++) {
        brightness += (*lights)[i];
    }

    return std::to_string(brightness);
}


TEST(GetInstructionTests, CanParseInstructions) {
    EXPECT_EQ(
            Instruction(std::pair(0, 0), std::pair(999, 999), Operation::On),
            getInstruction("turn on 0,0 through 999,999"));
    EXPECT_EQ(
            Instruction(std::pair(0, 0), std::pair(999, 0), Operation::Toggle),
            getInstruction("toggle 0,0 through 999,0"));
    EXPECT_EQ(
            Instruction(std::pair(499, 499), std::pair(500, 500), Operation::Off),
            getInstruction("turn off 499,499 through 500,500"));
}

SOLUTION_TEST(2015, 06, 1, examples) {
    EXPECT_EQ("998996", INVOKE_SOLUTION(2015, 06, 1, "turn on 0,0 through 999,999\ntoggle 0,0 through 999,0\nturn off 499,499 through 500,500"));
}

SOLUTION_TEST(2015, 06, 2, examples) {
    EXPECT_EQ("1001996", INVOKE_SOLUTION(2015, 06, 2, "turn on 0,0 through 999,999\ntoggle 0,0 through 999,0\nturn off 499,499 through 500,500"));
}