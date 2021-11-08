//
// Created by kamr on 11/6/2021.
//

#ifndef GNU_LONGESTPALINDROM_H
#define GNU_LONGESTPALINDROM_H

/*
Given array, find the longest palindrome subsequence.
    Input   => abaxyzzyxf
    Output  => xyzxyx

 * O(n^3) and no extra space. !!!
   each length -> n
   for each length (1 to string.length -1 ) {
        for ( i = 0; i < string.length - length, i++) {
            checkpalindrome(string, i, i + length)  -> keep highest value .
         }
    }
 *
 */

bool isPalindromeHelper(string str, int start, int len) {
    int  left, right;
    bool ret;
    bool  dbgLog = false ;

    left = start;
    ret = true;
    right = left + len - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            ret = false;
            break;
        }
        left = left + 1;
        right = right -1;
    }


    if (dbgLog) {
        right = start + len - 1;
        if (ret) {
            cout << str << ": start : " << start << " End: " << right << " Palindrome for string :" << len << " -> "
                 << str.substr(start, len) <<" is True " << endl;
        } else {
            cout << str << ": start : " << start << " End: " << right << " Palindrome for string :" << len << " -> "
                 << str.substr(start, len) <<" is False " << endl;
        }
    }
    return ret;
}

string
longestPalindromicSubstring(string str) {
    int maxPalindromeLength = -1;
    int currPalindromeLength = -1;
    int start = -1;
    int startIdx = -1;
    bool isPalindrome = false;
    int len = -1;
    bool dbgLog = false;


    if (str.length() == 0) {
        return  "";
    }

    if (str.length() == 1) {
        return str;
    }

    for (len = 0; len <= str.length(); len++) {
        isPalindrome = false;
        for (start = 0; start <= str.length() - len; start++) {
            isPalindrome = isPalindromeHelper(str, start, len);
            if (isPalindrome) {
                currPalindromeLength = len;
                break;
            }
            if (dbgLog) {
                cout << "isPalindrome for substr<local> <Len:" << len << ">: " << str.substr(start, len) << "-> :is: "
                     << isPalindrome << endl;
            }
        }
        if ((isPalindrome) && (currPalindromeLength > maxPalindromeLength)) {
            if (dbgLog) {
                cout << "isPalindrome for substr<Global> <Len:" << len << ">: " << str.substr(start, len) << "-> :is: "
                     << isPalindrome << endl;
            }
            maxPalindromeLength = currPalindromeLength;
            startIdx = start;
        }
    }
    if (maxPalindromeLength > 0) {
        return (str.substr(startIdx, maxPalindromeLength));
    } else {
        return "";
    }
}

void
test_longestPalindromicSubstring() {
    string str = "abaxyzzyxf";
    string subStr = longestPalindromicSubstring(str);


    cout << "--------------------------------------" << endl;
    cout << "Input :" << endl;
    cout << str << endl;
    cout << "Output" << endl;
    subStr = longestPalindromicSubstring(str);
    cout << subStr << endl;

    cout << "--------------------------------------" << endl;
    str = "it's highnoon";
    subStr = longestPalindromicSubstring(str);
    cout << "Input :" << endl;
    cout << str << endl;
    cout << "Output" << endl;
    cout << subStr << endl;


    cout << "--------------------------------------" << endl;
    str = "abcdefgfedcba";
    subStr = longestPalindromicSubstring(str);
    cout << "Input :" << endl;
    cout << "Length: " << str.length() << endl;
    cout << str << endl;
    cout << "Output" << endl;
    cout << subStr << endl;

    return;
}
#endif //GNU_LONGESTPALINDROM_H
