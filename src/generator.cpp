#include "generator.h"

std::string Generator::generateName(std::vector<std::string> prefixes,
                                    std::vector<std::string> sufixes)
{
    std::random_device device;
    std::mt19937 twister(device());

#ifdef DEBUG
    for (std::string &p : prefixes) {
        std::log << p << std::endl;
    }
#endif
    std::shuffle(prefixes.begin(), prefixes.end(), twister);
    std::shuffle(sufixes.begin(), sufixes.end(), twister);

#ifdef DEBUG
    for (std::string &p : prefixes) {
        std::log << p << std::endl;
    }
#endif

    _prefix = prefixes.empty() ? "" : prefixes[0];
    _sufix = sufixes.empty() ? "" : sufixes[0];

    return _prefix + _sufix;
}
