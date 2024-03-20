#include <map>
#include <string>
#ifndef NUMBERS_HPP
#define NUMBERS_HPP

namespace numbers {
struct Numbers {
    static std::string ones[];

    static std::string tens[];

    static std::string from11to19[];

    static const std::map<std::string, int> word_to_number;
};
} // namespace numbers
#endif
