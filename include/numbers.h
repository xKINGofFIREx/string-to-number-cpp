#include <map>
#include <string>

#ifndef NUMBERS_H
#define NUMBERS_H

namespace numbers {

static std::string ones[] = {"one", "two",   "tree",  "four", "five",
                             "six", "seven", "eight", "nine"};

static std::string tens[] = {"ten",   "twenty",  "thirty", "fourty", "fifty",
                             "sixty", "seventy", "eighty", "ninety"};

static std::string from11to19[] = {"eleven",    "twelve",   "thirteen",
                                   "fourteen",  "fifteen",  "sixteen",
                                   "seventeen", "eighteen", "nineteen"};

static const std::map<std::string, int> word_to_number{
    {"zero", 0},     {"one", 1},        {"two", 2},       {"three", 3},
    {"four", 4},     {"five", 5},       {"six", 6},       {"seven", 7},
    {"eight", 8},    {"nine", 9},       {"ten", 10},      {"eleven", 11},
    {"twelve", 12},  {"thirteen", 13},  {"fourteen", 14}, {"fifteen", 15},
    {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
    {"twenty", 20},  {"thirty", 30},    {"fourty", 40},   {"fifty", 50},
    {"sixty", 60},   {"seventy", 70},   {"eighty", 80},   {"ninety", 90},
    {"hundred", 100}};
}; // namespace numbers

#endif // numbers.h
