#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include "SolutionRegistry.h"

std::string get_input(uint id) {
    std::filesystem::path filepath{"Input/" + std::to_string((id / 10) % 200000) + ".txt"};
    std::ifstream file(filepath.make_preferred());
    if (!file.is_open())
        throw std::runtime_error("Failed to open file : " + filepath.string());

    std::string contents;
    file.seekg(0, std::ios::end);
    contents.resize(file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&contents[0], contents.size());
    file.close();

    return contents;
}

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