#include "search_engine.h"
#include <iostream>
#include <vector>
#include <algorithm>

void searchEngine(string query) {

    vector<string> words = parseQuery(query);

    unordered_map<string, int> scores;

    for (string word : words) {

        if (invertedIndex.find(word) == invertedIndex.end())
            continue;

        for (auto fileData : invertedIndex[word]) {
            scores[fileData.first] += fileData.second;
        }
    }

    if (scores.empty()) {
        cout << "No results found\n";
        return;
    }

    vector<pair<string, int>> ranked;

    for (auto s : scores) {
        ranked.push_back(s);
    }

    sort(ranked.begin(), ranked.end(),
        [](pair<string,int> a, pair<string,int> b) {
            return a.second > b.second;
        }
    );

    cout << "\n===== RESULTS =====\n";

    int count = 1;

    for (auto r : ranked) {

        cout << count << ". " << r.first
             << " | score: " << r.second << endl;

        count++;

        if (count > 10)
            break;
    }
}