//
// Created by kamr on 10/27/2021.
//

#ifndef GNU_STRINGAPITEST_H
#define GNU_STRINGAPITEST_H

#include <string>
#include <iostream>
using namespace std;

void test_stringAPI()
{
    string str  = "ahijklm";
    for (auto &C:str) {
        cout << C << " ";
    }
    cout << endl;
    cout << "Length of string:" << str <<": " << str.length() << endl;

    char ch;
    int key = 15;
    int diff;
    int add;
    for (auto &C:str) {
        diff = 'z' - C;
        if (diff > key) {
            ch = C + key;
            cout << "C:" << C << " Greater than z " << ch << " " << endl;
        } else {
            add = key - diff;
            ch = 'a' + add;
            cout << "C:" << C << " Less than z :" << ch << endl;
        }
    }

    /*---------------------------- Sorting API ---------------------------- */
    cout << "---------------------Sorting API -----------------------------" << endl;
    str = "yes";
    cout << str << endl;
    sort(str.begin(), str.end());
    cout << "String Sorting test " << endl;
    cout << str << endl;
    vector<string> words = {"hello", "yes", "hi" };
    for(string word:words) {
        cout << word << " ";
    }
    cout << endl;
    for (string &word: words) {
        sort(word.begin(), word.end());
    }
    for(string word:words) {
        cout << word << " ";
    }
    cout << endl;


    cout << endl;

}




#endif //GNU_STRINGAPITEST_H
