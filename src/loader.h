#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "debug.h"

namespace loader {
enum affix {prefix, suffix};
std::vector<std::string> load(affix);
}
