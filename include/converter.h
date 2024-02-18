#include <string>
#include <vector>

#include "numbers.h"

#ifndef CONVERTER_H_
#define CONVERTER_H_

using namespace numbers;

class Converter {
  private:
    static std::vector<std::string> split(const std::string &word_sequence);

    static bool is_word_correct(const std::string &word);

    static bool is_sequence_correct(const std::string &left,
                                    const std::string &right);
    static bool is_in(std::string array[], const std::string &word);

    static std::string get_format_type(const std::string &word);

  public:
    static std::string convert_string(const std::string &word_sequence);
};

#endif // converter.h
