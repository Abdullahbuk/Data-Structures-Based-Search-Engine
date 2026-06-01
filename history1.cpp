// history.cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<string> searchHistory;  // stack for history

void saveToHistory(string word) {
    searchHistory.push(word);  // push onto stack
}

void showHistory() {
    cout << "\n--- Search History ---" << endl;
    stack<string> temp = searchHistory;

    while (!temp.empty()) {
        cout << "  " << temp.top() << endl;
        temp.pop();
    }
}

void undoLastSearch() {
    if (!searchHistory.empty()) {
        cout << "Removing last search: " << searchHistory.top() << endl;
        searchHistory.pop();  // pop from stack
    } else {
        cout << "No history to undo." << endl;
    }
}