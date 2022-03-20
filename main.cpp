#include <chrono>
#include "Common.h"

int main() {
    for (const auto& solution : SolutionRegistry::GetSolutions()) {
        auto id = solution.first;
        auto input = get_input(id);

        auto start = std::chrono::steady_clock::now();
        auto output = solution.second(input);
        auto end = std::chrono::steady_clock::now();
        std::cout << std::to_string(id) << " : " << output << " : " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us" << std::endl;

    }
    return 0;
}