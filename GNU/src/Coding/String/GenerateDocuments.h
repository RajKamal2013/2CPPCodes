//
// Created by kamr on 10/27/2021.
//

#ifndef GNU_GENERATEDOCUMENTS_H
#define GNU_GENERATEDOCUMENTS_H

bool generateDocument(string characters, string document) {
    unordered_map<char, int> charMap;

    for (auto &ch:characters) {
        if (charMap.find(ch) == charMap.end()) {
            charMap[ch] = 0;
        }
        charMap[ch]++;
    }

    for (auto &ch:document) {
        if ((charMap.find(ch) == charMap.end()) || (charMap[ch] == 0)) {
            return false;
        }
        charMap[ch]--;
    }

    return true;
}

void
test_generateDocument() {

    string characters = "Bste!hetsi ogEAxpelrt x ";
    string document = "AlgoExpert is the Best!";

    bool res = generateDocument(characters, document);
    cout << characters << endl;
    cout << document << endl;
    cout << res << endl;
}

#endif //GNU_GENERATEDOCUMENTS_H
