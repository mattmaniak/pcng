#pragma once

#include <algorithm>
#include <random>
#include <string>
#include <vector>

#include <iostream>

#include "debug.h"
#include "loader.h"

class Generator
{
public:
    std::string generateName(std::vector<std::string>,
                             std::vector<std::string>);

private:
    std::string _suffix;
    std::string _prefix;

    void _log(loader::affix);
};