//
// Created by Alexander on 13.10.2023.
//

#include "gtest/gtest.h"
#include "../FileReader.h"

TEST(FileReader, EmptyFile) {
    std::ofstream test_file("empty_file.txt");
    test_file.close();

    FileReader fileReader("empty_file.txt");
    fileReader.open();

    ASSERT_EQ(fileReader.getNext(), "");
    ASSERT_FALSE(fileReader.hasNext());
}

TEST(FileReader, SingleLine) {
    std::ofstream test_file("single_line.txt");
    test_file << "single line test";
    test_file.close();

    FileReader fileReader("single_line.txt");
    fileReader.open();

    ASSERT_TRUE(fileReader.hasNext());

    std::string line = fileReader.getNext();

    ASSERT_EQ(line, "single line test");
}

TEST(FileReader, MultiLine) {
    std::ofstream test_file("multi_line.txt");
    test_file << "this string\nspans\nmultiple lines";
    test_file.close();

    FileReader fileReader("multi_line.txt");
    fileReader.open();

    ASSERT_EQ(fileReader.getNext(), "this string");
    ASSERT_EQ(fileReader.getNext(), "spans");
    ASSERT_EQ(fileReader.getNext(), "multiple lines");
    ASSERT_FALSE(fileReader.hasNext());
}