#include "search_engine.h"
#include <iostream>

using namespace std;

int main() {

    cout << "==============================\n";
    cout << " MINI DESKTOP SEARCH ENGINE\n";
    cout << "==============================\n";

    string path;

    cout << "Enter folder path: ";
    getline(cin, path);

    cout << "\nCrawling files...\n";

    queue<string> files = crawl(path);

    cout << "Files found: " << files.size() << endl;

    cout << "\nBuilding index...\n";

    buildIndex(files);

    while (true) {

        string query;

        cout << "\nSearch (or exit): ";
        getline(cin, query);

        if (query == "exit")
            break;

        searchEngine(query);
    }

    return 0;
}