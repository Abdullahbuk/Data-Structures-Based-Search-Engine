#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

extern unordered_map<string, unordered_map<string, int>> invertedIndex;

// parser
string cleanWord(string word);
vector<string> parseQuery(string query);
bool hasValidExtension(const string& filename);

// crawler
queue<string> crawl(string folderPath);

// indexer
void buildIndex(queue<string> files);

// search
void searchEngine(string query);

// AI summary
void summarizeFile(string filepath);

#endif