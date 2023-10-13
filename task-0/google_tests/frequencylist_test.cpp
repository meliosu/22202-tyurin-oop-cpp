//
// Created by Alexander on 13.10.2023.
//

#include "gtest/gtest.h"
#include "../FrequencyList.h"

TEST(FrequencyList, NonUniqueWords) {
    FrequencyList frequencyMap;

    frequencyMap.addWord("one");

    frequencyMap.addWord("three");
    frequencyMap.addWord("three");
    frequencyMap.addWord("three");

    frequencyMap.addWord("two");
    frequencyMap.addWord("two");

    ASSERT_EQ(frequencyMap.getWordCount(), 6);

    std::vector<std::pair<std::string, int>> sortedList = frequencyMap.getSortedList();

    ASSERT_EQ(sortedList[0].first, "three");
    ASSERT_EQ(sortedList[0].second, 3);
    ASSERT_EQ(sortedList[1].first, "two");
    ASSERT_EQ(sortedList[1].second, 2);
    ASSERT_EQ(sortedList[2].first, "one");
    ASSERT_EQ(sortedList[2].second, 1);
}

TEST(FrequencyList, UniqueWords) {
    FrequencyList frequencyMap;

    frequencyMap.addWord("abc");
    frequencyMap.addWord("123");
    frequencyMap.addWord("def");

    ASSERT_EQ(frequencyMap.getWordCount(), 3);
}

TEST(FrequencyList, EmptyList) {
    FrequencyList emptyMap;

    std::vector<std::pair<std::string, int>> emptySortedList = emptyMap.getSortedList();

    ASSERT_EQ(emptySortedList.size(), 0);
}