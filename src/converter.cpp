#include "converter.h"
#include <vector>

std::vector<std::string> Converter::split(const std::string &word_sequence) {
    std::vector<std::string> words;
    std::string word = "";

    for (auto it = word_sequence.begin(); it < word_sequence.end(); ++it) {
        if (*it != ' ') {
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
        int word_num = word_to_number.at(word);
    } catch (const std::out_of_range &e) {
        return false;
    }

    return true;
}

bool Converter::is_sequence_correct(const std::string &left,
                                    const std::string &right) {
    if (is_in(ones, right) && (is_in(tens, left) || left == "hundred"))
        return true;

    if (is_in(tens, right) && left == "hundred")
        return true;

    if (is_in(from11to19, right) && left == "hundred")
        return true;

    if (right == "hundred" && is_in(ones, left))
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

    unsigned int result_number = word_to_number.at(words[0]);

    for (int i = 1; i < words.size(); ++i) {
        if (!is_word_correct(words[i])) {
            return "Слово - " + words[i] + " содержит ошибку";
        }

        if (!is_sequence_correct(words[i - 1], words[i])) {
            return "Oшибка последовательности - " + words[i - 1] + " " +
                   words[i];
        }
        if (words[i] == "hundred") {
            result_number *= 100;
        } else {
            result_number += word_to_number.at(words[i]);
        }
    }

    return std::to_string(result_number);
}
