//
// Created by kamr on 10/26/2021.
//

#ifndef GNU_PALINDROME_H
#define GNU_PALINDROME_H

#include <string>
#include <iostream>
using namespace std;


bool isPalindrome(string str) {
    bool ret = true;
    int left, right;
    bool test = true;

    if ((str.empty()) || (str.length() == 0)) {
        return ret;
    }

    left = 0;
    right = str.length() - 1;
    if (test) {
        cout << "length of string : "<< str << ":" << str.length() << endl;
    }
    while (left < right) {
        if (str[right] != str[left]) {
            ret = false;
            break;
        }
        left++;
        right--;
    }
    return ret;
}

void
test_isPaindrome()
{
    string str1 = "";
    string str2 = " ";
    string str3 = "abba";
    string str4 = "abcdcba";
    string str5 = "abcdefghihgfedcba";
    string str6 = "abcd";
    bool ret;

    ret = isPalindrome(str1);
    cout << "String:" << str1 << " is Palindrome: " << ret<< endl;
    ret = isPalindrome(str2);
    cout << "String:" << str2 << " is Palindrome: " << ret<< endl;
    ret = isPalindrome(str3);
    cout << "String:" << str3 << " is Palindrome: " << ret<< endl;
    ret = isPalindrome(str4);
    cout << "String:" << str4 << " is Palindrome: " << ret<< endl;
    ret = isPalindrome(str5);
    cout << "String:" << str5 << " is Palindrome: " << ret<< endl;
    ret = isPalindrome(str6);
    cout << "String:" << str6 << " is Palindrome: " << ret<< endl;
}

#endif //GNU_PALINDROME_H
