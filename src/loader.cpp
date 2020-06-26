#include "loader.h"

std::vector<std::string> loader::load(loader::affix mode)
{
    std::vector<std::string> words;
    std::ifstream file;
    std::string line;

    switch (mode) {
    case prefix:
        file.open("res/prefixes");
        break;

    case sufix:
        file.open("res/sufixes");
    }

    if (file.is_open()) {
        while (getline(file, line)) {
            words.push_back(line);
        }
    }
    file.close();

    return words;
}