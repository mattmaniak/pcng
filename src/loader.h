#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace loader {
enum affix {prefix, sufix};
std::vector<std::string> load(affix);
}
