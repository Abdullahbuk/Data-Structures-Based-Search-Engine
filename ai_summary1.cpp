#include "search_engine.h"
#include <fstream>
#include <iostream>

void summarizeFile(string filepath) {

    ifstream file(filepath);

    if (!file.is_open()) {
        cout << "Cannot open file\n";
        return;
    }

    cout << "\n===== AI SUMMARY =====\n";

    string line;
    int lines = 0;

    while (getline(file, line) && lines < 5) {
        cout << line << endl;
        lines++;
    }

    file.close();
}