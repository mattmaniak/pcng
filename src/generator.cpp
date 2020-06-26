#include "generator.h"

std::string Generator::generateName(std::vector<std::string> prefixes,
                                    std::vector<std::string> suffixes)
{
    std::random_device device;
    std::mt19937 twister(device());

    std::shuffle(prefixes.begin(), prefixes.end(), twister);
    std::shuffle(suffixes.begin(), suffixes.end(), twister);

    _prefix = prefixes.empty() ? "" : prefixes[0];
    _suffix = suffixes.empty() ? "" : suffixes[0];

    while (_prefix == _suffix) {
        std::shuffle(suffixes.begin(), suffixes.end(), twister);
        _suffix = suffixes.empty() ? "" : suffixes[0];
    }
    return _prefix + _suffix;
}
