#include "converter.hpp"
#include <algorithm>
#include <numbers.hpp>
#include <stdexcept>
#include <string>
#include <vector>

using namespace numbers;

std::vector<std::string> Converter::split(const std::string &word_sequence) {
    std::vector<std::string> words;
    std::string word = "";

    for (auto it = word_sequence.begin(); it < word_sequence.end(); ++it) {
        if (*it != ' ' && *it != '\n') {
            word += *it;
        } else if (word.size() != 0 && *it == ' ') {
            words.push_back(word);
            word = "";
        }
    }

    if (word.size() != 0)
        words.push_back(word);

    return words;
};

bool Converter::is_word_correct(const std::string &word) {

    try {
        int word_num = Numbers::word_to_number.at(word);
    } catch (const std::out_of_range &e) {
        return false;
    }

    return true;
}

bool Converter::is_sequence_correct(const std::string &left,
                                    const std::string &right) {
    if (is_in(Numbers::ones, right) &&
        (is_in(Numbers::tens, left) || left == "hundred"))
        return true;

    if (is_in(Numbers::tens, right) && left == "hundred")
        return true;

    if (is_in(Numbers::from11to19, right) && left == "hundred")
        return true;

    if (right == "hundred" && is_in(Numbers::ones, left))
        return true;

    return false;
}

bool Converter::is_in(std::string array[], const std::string &word) {
    for (int i = 0; i < 9; ++i) {
        if (array[i] == word)
            return true;
    }

    return false;
}

std::string Converter::get_format_type(const std::string &word) {
    if (is_in(Numbers::ones, word) || word == "zero")
        return "единичного формата";
    if (is_in(Numbers::tens, word))
        return "десятичного формата";
    if (is_in(Numbers::from11to19, word))
        return "формата 11-19";
    return "формата сотен";
}

std::string Converter::convert_string(const std::string &word_sequence) {
    std::string lowercase_string = "";
    std::for_each(word_sequence.begin(), word_sequence.end(),
                  [&lowercase_string](unsigned char c) {
                      lowercase_string.push_back(std::tolower(c));
                  });

    std::vector<std::string> words = split(lowercase_string);

    if (words.size() == 0)
        return "Строка не может быть пустой";

    if (!is_word_correct(words[0])) {
        return "Слово - " + words[0] + " содержит ошибку";
    }

    if (words[0] == "hundred")
        return "Перед словом hundred должно стоять число единичного "
               "формата";

    if (words[0] == "zero")
        return "Число не может начинаться с нуля";

    unsigned int result_number = Numbers::word_to_number.at(words[0]);

    for (int i = 1; i < words.size(); ++i) {
        if (!is_word_correct(words[i])) {
            return "Слово - " + words[i] + " содержит ошибку";
        }

        if (words[i] == "zero")
            return "Ноль может быть только отдельной цифрой";

        if (!is_sequence_correct(words[i - 1], words[i])) {
            return "Число " + get_format_type(words[i - 1]) + " - " +
                   words[i - 1] + " не может идти перед числом " +
                   get_format_type(words[i]) + " - " + words[i];
        }
        if (words[i] == "hundred") {
            result_number *= 100;
        } else {
            result_number += Numbers::word_to_number.at(words[i]);
        }
    }

    if (result_number > 999)
        return "Число задается в диапазоне 0-999";

    return std::to_string(result_number);
}
