#include "generator.h"

std::string Generator::generateName(std::vector<std::string> prefixes,
                                    std::vector<std::string> suffixes)
{
    std::random_device device;
    std::mt19937 twister(device());

#ifdef DEBUG
    for (std::string &p : prefixes) {
        std::cout << p << std::endl;
    }
#endif
    std::shuffle(prefixes.begin(), prefixes.end(), twister);
    std::shuffle(suffixes.begin(), suffixes.end(), twister);

#ifdef DEBUG
    for (std::string &s : suffixes) {
        std::cout << s << std::endl;
    }
#endif

    _prefix = prefixes.empty() ? "" : prefixes[0];
    _suffix = suffixes.empty() ? "" : suffixes[0];

    return _prefix + _suffix;
}
