//
// Created by kamr on 11/6/2021.
//

#ifndef GNU_GROUPANAGRAM_H
#define GNU_GROUPANAGRAM_H
/*
 * Group Anagrams
 *   Given a list of string, we need to group anagrams together.

 *   Create a copy of strings. -> Copy
 *   for each element in Copy
        1. sort the element using inbuilt Function
     for each word in Copy
        find duplicate of words (Anagram after sorting becomes same word.)
        coy all words in indices and remove from the Copy and place in another list

 *  Words = {"yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp"}

 * Output -> {{"yo", "oy"}, {"flop", "olfp"}, {"act", "tac", "cat"}, {"foo"}}
 */

vector<vector<string>>
groupAnagrams(vector<string> words) {
    // empty string
    if (words.size() == 0) {
        return {};
    }
    // only one element
    if (words.size() == 1) {
        vector<vector<string>> groupAnagramsList;
        vector<string> anagram;
        anagram.push_back(words[0]);
        groupAnagramsList.push_back(anagram);
        return groupAnagramsList;
    }
    /* copy the words into another aux list to copy its content */
    vector<string> aux;
    /* copy */
    for (auto word:words) {
        aux.push_back(word);
    }

    /* Sort every word in words using builtin sort function */
    for (string &word:words) {
        sort(word.begin(), word.end());
    }

    // temp to hold current word
    string word = "";
    // output vector
    vector<vector<string>> groupAnagramsList;
    vector<string> anagram;
    for (int idx1 = 0; idx1 < words.size(); idx1++) {
        // every word we put in output array, we place empty string in place of it
        if (words[idx1] == "") {
            continue;
        }
        word = words[idx1];
        // clear the list before reusing.
        anagram.clear();
        // place the corresponding word in idx1
        anagram.push_back(aux[idx1]);
        // mark empty at position idx1
        words[idx1]="";
        for (int idx2= idx1 + 1; idx2 < words.size(); idx2++) {
            // every word we put in output array, we place empty string in place of it
            if (words[idx2] == "") {
                continue;
            }
            // we found anagram
            if (words[idx2] == word) {
                anagram.push_back(aux[idx2]);
                words[idx2] = "";
            }
        }
        groupAnagramsList.push_back(anagram);
    }

    for (int idx = 0; idx < aux.size(); idx++) {
        words[idx] = aux[idx];
    }
    aux.clear();
    return groupAnagramsList;
}

void
test_groupAnagrams() {
    vector<string> wordsList;
    vector<vector<string>> anagramsList;

    cout<< "-------------------------------------------------------------" << endl;
    wordsList = {"yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp"};
    anagramsList = groupAnagrams(wordsList);
    cout << "Inputs" << endl;
    for (auto word:wordsList) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Output " << endl;
    for (auto words:anagramsList) {
        cout << "{ ";
        for  (auto word:words) {
            cout << word << " ";
        }
        cout << " }";
    }
    cout << endl;

}

#endif //GNU_GROUPANAGRAM_H
