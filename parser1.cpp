#include "search_engine.h"
#include <sstream>
#include <cctype>

string cleanWord(string word) {
    string clean = "";

    for (char c : word) {
        unsigned char uc = static_cast<unsigned char>(c);

        if (isalnum(uc)) {
            clean += tolower(uc);
        }
    }

    return clean;
}

vector<string> parseQuery(string query) {
    vector<string> words;
    stringstream ss(query);
    string word;

    while (ss >> word) {
        words.push_back(cleanWord(word));
    }

    return words;
}

bool hasValidExtension(const string& filename) {
    vector<string> exts = {
        ".txt",
        ".cpp",
        ".h",
        ".py",
        ".json"
    };

    for (string ext : exts) {
        if (filename.size() >= ext.size() &&
            filename.substr(filename.size() - ext.size()) == ext) {
            return true;
        }
    }

    return false;
}