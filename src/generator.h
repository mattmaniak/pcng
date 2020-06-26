#pragma once

#include <algorithm>
#include <random>
#include <string>
#include <vector>

#include <iostream>

#include "loader.h"

class Generator
{
public:
    std::string generateName(std::vector<std::string>,
                             std::vector<std::string>);

private:
    std::string _sufix;
    std::string _prefix;
};