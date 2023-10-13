//
// Created by Alexander on 13.10.2023.
//

#include "gtest/gtest.h"
#include "../Parser.h"

TEST(Parser, RegularString) {
    Parser parser;

    std::string regular_string = "abc 123 def";
    std::list<std::string> words = parser.parse(regular_string);

    ASSERT_EQ(words.size(), 3);
    ASSERT_EQ(words, std::list<std::string>({"abc", "123", "def"}));
}

TEST(Parser, UppercaseString) {
    Parser parser;

    std::string uppercase_string = "UPPER CASE";
    std::list<std::string> words = parser.parse(uppercase_string);

    ASSERT_EQ(words.size(), 2);
    ASSERT_EQ(words, std::list<std::string>({"upper", "case"}));

}

TEST(Parser, NonSpaceSeparators) {
    Parser parser;

    std::string test_string = "These&words*)are $ separated#%#by&*)$#%";
    std::list<std::string> words = parser.parse(test_string);

    ASSERT_EQ(words.size(), 5);
    ASSERT_EQ(words, std::list<std::string>({"these", "words", "are", "separated", "by"}));
}

TEST(Parser, EmptyString) {
    Parser parser;

    std::string empty_string;
    std::list<std::string> words = parser.parse(empty_string);

    ASSERT_EQ(words.size(), 0);
}
