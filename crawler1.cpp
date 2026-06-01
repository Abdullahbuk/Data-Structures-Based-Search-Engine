#include "search_engine.h"
#include <windows.h>
#include <iostream>

queue<string> crawl(string folderPath) {
    queue<string> files;

    string searchPath = folderPath + "\\*";

    WIN32_FIND_DATA data;

    HANDLE hFind = FindFirstFile(searchPath.c_str(), &data);

    if (hFind == INVALID_HANDLE_VALUE) {
        return files;
    }

    do {
        string name = data.cFileName;

        if (name == "." || name == "..")
            continue;

        string fullPath = folderPath + "\\" + name;

        if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            queue<string> subFiles = crawl(fullPath);

            while (!subFiles.empty()) {
                files.push(subFiles.front());
                subFiles.pop();
            }
        }
        else {
            if (hasValidExtension(name)) {
                files.push(fullPath);
            }
        }

    } while (FindNextFile(hFind, &data));

    FindClose(hFind);

    return files;
}