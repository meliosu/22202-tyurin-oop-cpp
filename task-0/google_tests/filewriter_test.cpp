//
// Created by Alexander on 13.10.2023.
//

#include "gtest/gtest.h"
#include "../FileWriter.h"

TEST(FileWriter, EmptyList) {
    FileWriter fileWriter("empty_list.csv");
    fileWriter.open();

    FrequencyList emptyFrequencyList;

    fileWriter.writeFrequencyList(emptyFrequencyList);
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

    fileWriter.writeFrequencyList(frequencyList);
    fileWriter.close();

    std::ifstream test_file("regular_list.csv");
    std::string line;

    std::getline(test_file, line);
    ASSERT_EQ(line, "word;absFrequency;relFrequency");

    std::getline(test_file, line);
    ASSERT_EQ(line, "six;6;60");

    std::getline(test_file, line);
    ASSERT_EQ(line, "four;4;40");

    std::getline(test_file, line);
    ASSERT_EQ(line, "");

    ASSERT_TRUE(test_file.eof());
}