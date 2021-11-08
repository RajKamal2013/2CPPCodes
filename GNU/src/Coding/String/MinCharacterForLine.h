//
// Created by kamr on 11/6/2021.
//

#ifndef GNU_MINCHARACTERFORLINE_H
#define GNU_MINCHARACTERFORLINE_H

#include <unordered_map>
/*
 * minimum characters for word
    -> given array of words -> give minimum number of character require to compose the array.

    ["y, "r", "o", "u"] is needed to make ["you", "yours", "or", "yo"]

    Input: {"this", "that", "did", "deed", "them!", "a"}
    Output: -> {"t", "t", "h", "i", "s", "a", "d", "d", "e", "e",  "m", "!"}

unordered_map -> char -> count.

1. keep unordered_map -> global to keep account of minimum number of charcaters needed to create words
2. Keep local unordered_map to count of characters in word
3. keep local and global in sync

 */

vector<char>
minimumCharactersForWords(vector<string> words) {
    if (words.size() == 0) {
        return {};
    }
    // local unordered map to track characters in word
    unordered_map<char, int> local_map;
    // global unordered map to track characters globally
    unordered_map<char, int> global_map;

    bool dbgLog = false;

    // iterate every word in array
    for (string word:words) {
        local_map.clear();
        for (char ch:word) {
            // we did added the character to local list yet
            if (local_map.find(ch) == local_map.end()) {
                local_map[ch] = 0;
            }
            // character is occuring more than one
            local_map[ch]++;
        }
        // sync with global
        for (auto entry : local_map) {
            // local entry does not exist in  global
            if (global_map.find(entry.first) == global_map.end()) {
                global_map[entry.first] = entry.second;
            } else if (global_map[entry.first] < entry.second) {
                global_map[entry.first] = entry.second;
            } else {
                // do nothing
            }
        }
        if (dbgLog) {
            //cout << entry.first << " " << entry.second << endl;
        }
    }

    // covert the map to array
    vector <char> str;
    // iterate global map
    for (auto entry : global_map) {
        if (entry.first == 1) {
            // first time occurrences
            str.push_back(entry.first);
        } else {
            // more than one occurrences of character in a word
            for (int i = 0; i < entry.second; i++) {
                str.push_back(entry.first);
            }
        }
    }
    return str;
}

void
test_minimumCharactersForWords() {
    vector<string> words={};
    vector<char> characters = {};

    cout << "-----------------------------------------------" << endl;
    words = {"this", "that", "did", "deed", "them!", "a"};
    cout << "Input < words >" << endl;
    for (auto word:words) {
        cout << word << " ";
    }
    cout << endl;
    characters = minimumCharactersForWords(words);
    cout << "Output < characters needed to make words >" << endl;
    for (auto character:characters) {
        cout << character << " ";
    }
    cout << endl;
}
#endif //GNU_MINCHARACTERFORLINE_H
