//
// Created by Shawn White on 3/20/22.
//

#include <fstream>
#include <filesystem>
#include "Common.h"

std::string get_input(uint id) {
    std::filesystem::path filepath{"Input/" + std::to_string((id / 10) % 200000) + ".txt"};
    std::ifstream file(filepath.make_preferred());
    if (!file.is_open())
        throw std::runtime_error("Failed to open file : " + filepath.string());

    std::string contents;
    file.seekg(0, std::ios::end);
    contents.resize(file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&contents[0], (std::streamsize)contents.size());
    file.close();

    return contents;
}