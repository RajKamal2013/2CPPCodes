//
// Created by kamr on 11/6/2021.
//

#ifndef GNU_REVERSELINE_H
#define GNU_REVERSELINE_H
/*
 * Reverse Words In String
 *
 * Given a line. Reverse the words in the line
 * Input ->  AlgoExpert is the best!
 * Output -> best! the is AlgoExpert
 *
 * you cant use reverse built in API
 *
 * Iterate line and for every word encounter, place in array and also place the amount of
 * space
 * Join the array to form the output
*/
string
reverseWordsInString(string str) {
    bool dbgLog = false;
    /* empty string */
    if (str == "") {
        return "";
    }

    /* Iterate string and store the words in vector */
    /* array to store words in str */
    vector<string> words = {};
    // use to keep the current word
    string word = "";
    // space -> use to account space
    string  space = "";
    /* iterate string */
    for (int idx = 0; idx < str.length(); idx++) {
        if (str[idx] == ' ') { //space
            if (word != "") {
                words.push_back(word);  //place word in words
                word = "";
            }
            space  = space + str[idx];
        } else { // word
            if (space != "") {
                words.push_back(space); //place the space in words
                space = "";
            }
            word = word + str[idx];
        }
    }

    // last one
    if (word != "") {
        words.push_back(word);
        word = "";
    } else if (space != "") {
        words.push_back(space);
        space = "";
    } else {
        // do nothing. <both are null >
    }
    if (dbgLog) {
        for (auto data:words) {
            cout << data << "--";
        }
        cout << endl;
    }

    // calculate the size of words that will be used to create reverse string
    int count = words.size();
    string reverseStr = "";
    for (int idx = count - 1; idx >= 0; idx--) {
        reverseStr = reverseStr + words[idx];
    }

    if (dbgLog) {
        cout << "Reverse :" << reverseStr << endl;
    }
    return reverseStr;
}

void
test_reverseString() {
    string str = "";
    string revStr = "";

    cout << "--------------------------------------------" << endl;
    cout << "Input <Line>:" << endl;
    str = "AlgoExpert is the best!";
    cout << str;
    cout << endl;
    cout << "Output <reverse Line> " << endl;
    revStr = reverseWordsInString(str);
    cout << revStr;
    cout << endl;
}

#endif //GNU_REVERSELINE_H
