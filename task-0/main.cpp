#include "FileReader.h"
#include "Parser.h"
#include "FrequencyList.h"
#include "FileWriter.h"

#include <string>
#include <list>

using std::string;

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
        for (auto word : words) {
            frequencyList.addWord(word);
        }
    }

    FileWriter fileWriter(argv[2]);
    fileWriter.open();

    fileWriter.writeFrequencyList(&frequencyList);

    fileReader.close();
    fileWriter.close();

    return 0;
}
