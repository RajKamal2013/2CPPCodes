//
// Created by kamr on 11/17/2021.
//

#ifndef GNU_CANBEPALINDROME_H
#define GNU_CANBEPALINDROME_H


// can it be palindrome
#include <unordered_map>
#include <iostream>
using namespace std;
/*
ABA => true
AAB => ABA => true
BCA => false
*/
bool isPalindrome(string str) {
    int start = 0;
    int end = str.length();
    int ret = true;

    while (start < end) {
        if (str[start] != str[end]) {
            ret = false;
            break;
        }
        start = start + 1;
        end = end - 1;
    }
    return ret;
}

bool can_be_palindrome(string str)
{
    //string str1 = to_string(str);
    if ((str.length() == 0) || (str.length() == 1)) {
        return true;
    }

    bool ret = isPalindrome(str);
    if (ret) {
        return true;
    }
    // not palindrome in current form
    unordered_map<char, int> frequencyMap = {};
    for (auto ch:str) {
        // still not in hash
        if (frequencyMap.find(ch) == frequencyMap.end()) {
            frequencyMap[ch] = 1;
        } else {
            frequencyMap[ch] = frequencyMap[ch] + 1;
        }
    }
    int oddCount = 0;
    for (auto frequency:frequencyMap) {
        if ((frequency.second % 2) == 0) {
            //even case
        } else {
            oddCount = oddCount + 1;
        }
    }

    if (oddCount > 1) {
        return false;
    }else {
        return true;
    }
}

void
test_canbePalindrome()
{
    string str = "ABCABC";
    cout << "String:" << str << endl;
    bool ret;
    ret = can_be_palindrome(str);
    cout << "can be Palindrome:" << ret << endl;


    str = "ABCAB";
    cout << "String:" << str << endl;
    ret = can_be_palindrome(str);
    cout << "can be Palindrome:" << ret << endl;

    str = "ABCABCDE";
    cout << "String:" << str << endl;
    ret = can_be_palindrome(str);
    cout << "can be Palindrome:" << ret << endl;
}
#endif //GNU_CANBEPALINDROME_H
