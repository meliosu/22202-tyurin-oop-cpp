#include "FileReader.h"
#include "Parser.h"
#include "FrequencyList.h"
#include "FileWriter.h"

#include <string>
#include <list>

using std::string;

const std::vector<string> CSV_FIELDS = {"word", "absFrequency", "relFrequency"};

int main(int argc, char** argv) {
    if (argc < 3) {
        exit(1);
    }

    FileReader fileReader(argv[1]);
    fileReader.open();

    Parser parser;
    FrequencyList frequencyList;

    while (fileReader.hasNext()) {
        string line = fileReader.getNext();
        std::list<string> words = parser.parse(line);
        for (string const& word : words) {
            frequencyList.addWord(word);
        }
    }

    FileWriter fileWriter(argv[2]);
    fileWriter.open();

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

    fileReader.close();
    fileWriter.close();

    return 0;
}
