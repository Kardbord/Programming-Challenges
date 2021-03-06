//
// Created by Tanner on 6/1/2017.
//

#include <stdexcept>
#include "Utils.h"

std::vector<std::string> Utils::parseString(std::string s, std::string const &delim, int const expected_tokens) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    while ((pos = s.find(delim)) != std::string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + delim.length());
    }

    // Place the last token into the vector.
    // This is not done in the while loop because the delim will not be found the last time through.
    tokens.push_back(s);

    if (tokens.size() != expected_tokens) {
        throw std::invalid_argument("expected_tokens did not match the number of tokens parsed");
    }

    return tokens;
}

std::vector<std::string> Utils::parseString(std::string s, std::string const &delim) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    while ((pos = s.find(delim)) != std::string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + delim.length());
    }

    // Place the last token into the vector.
    // This is not done in the while loop because the delim will not be found the last time through.
    tokens.push_back(s);

    return tokens;
}
