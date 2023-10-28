//
// Created by Alexander on 13.10.2023.
//

#include "gtest/gtest.h"
#include "../FileWriter.h"

const std::vector<string> CSV_FIELDS = {"word", "absFrequency", "relFrequency"};

TEST(FileWriter, EmptyList) {
    FileWriter fileWriter("empty_list.csv");
    fileWriter.open();

    FrequencyList emptyFrequencyList;

    std::vector<std::pair<string, int>> sortedList = emptyFrequencyList.getSortedList();
    int wordsCount = emptyFrequencyList.getWordsCount();

    fileWriter.writeVec(CSV_FIELDS, ';');
    for (const std::pair<string, int>& wordPair : sortedList) {
        string word = wordPair.first;
        int absFrequency = wordPair.second;
        double relFrequency = (double)wordPair.second / wordsCount * 100;

        std::vector<string> wordData = {word, std::to_string(absFrequency), std::to_string(relFrequency)};
        fileWriter.writeVec(wordData, ';');
    }

    fileWriter.close();

    std::ifstream test_file("empty_list.csv");
    std::string line;

    std::getline(test_file, line);
    ASSERT_EQ(line, "word;absFrequency;relFrequency");
}

TEST(FileWriter, RegularList) {
    FileWriter fileWriter("regular_list.csv");
    fileWriter.open();

    FrequencyList frequencyList;

    for (int i = 0; i < 4; i++) {
        frequencyList.addWord("four");
    }

    for (int i = 0; i < 6; i++) {
        frequencyList.addWord("six");
    }

    std::vector<std::pair<string, int>> sortedList = frequencyList.getSortedList();
    int wordsCount = frequencyList.getWordsCount();

    fileWriter.writeVec(CSV_FIELDS, ';');
    for (const std::pair<string, int>& wordPair : sortedList) {
        string word = wordPair.first;
        int absFrequency = wordPair.second;
        double relFrequency = (double)wordPair.second / wordsCount * 100;

        std::vector<string> wordData = {word, std::to_string(absFrequency), std::to_string(relFrequency)};
        fileWriter.writeVec(wordData, ';');
    }

    fileWriter.close();

    std::ifstream test_file("regular_list.csv");
    std::string line;

    std::getline(test_file, line);
    ASSERT_EQ(line, "word;absFrequency;relFrequency");

    std::getline(test_file, line);
    ASSERT_EQ(line, "six;6;60.000000");

    std::getline(test_file, line);
    ASSERT_EQ(line, "four;4;40.000000");

    std::getline(test_file, line);
    ASSERT_EQ(line, "");

    ASSERT_TRUE(test_file.eof());
}