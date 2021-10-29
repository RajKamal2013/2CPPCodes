//
// Created by kamr on 10/27/2021.
//

#ifndef GNU_FIRSTNONREPEATINGCHARACTER_H
#define GNU_FIRSTNONREPEATINGCHARACTER_H

int firstNonRepeatingCharacter(string str) {
    unordered_map<char, int> hash;
    for (auto &ch:str) {
        if (hash.find(ch) == hash.end()) {
            hash[ch] = 0;
        }
        hash[ch]++;
    }

    for (int i = 0; i < str.length(); i++) {
        if (hash[str[i]] == 1) {
            return i;
        }
    }
    return -1;
}

void
test_firstNonRepeatingCharacter() {
    string str;
    int idx;

    str = "abcdcaf";
    idx = firstNonRepeatingCharacter(str);
    cout << "Input Str:" << str << endl;
    if (idx != -1) {
        cout << "Index of first non repeating character<" << str[idx] << ">" << ": "<<idx <<endl;
    } else {
        cout << "All characters are repeating " << endl;
    }
}
#endif //GNU_FIRSTNONREPEATINGCHARACTER_H
