#include "search_engine.h"
#include <fstream>
#include <iostream>

unordered_map<string, unordered_map<string, int>> invertedIndex;

void buildIndex(queue<string> files) {

    int fileCount = 0;

    while (!files.empty()) {

        string filepath = files.front();
        files.pop();

        ifstream file(filepath);

        if (!file.is_open()) {
            continue;
        }

        string word;

        while (file >> word) {

            string clean = cleanWord(word);

            if (!clean.empty()) {
                invertedIndex[clean][filepath]++;
            }
        }

        file.close();
        fileCount++;
    }

    cout << "Indexed files: " << fileCount << endl;
}