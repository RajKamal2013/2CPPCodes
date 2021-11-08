//
// Created by kamr on 11/4/2021.
//

#ifndef GNU_BALACEDBRACKETS_H
#define GNU_BALACEDBRACKETS_H

/*
Takes a string and returns if the brackets are balanced in the string.
Input -> ([])(){}(())()()
Output -> yes

    brackets can't overlap -> [(])
*/
/*
  if string is any of [, {, (    -> push
  if string is any of ], }, )    -> if (top == string )-> pop
  if (stack is empty ) -> we have balanced brackets.
*/

bool balancedBrackets(string str) {
    stack<char> brackets = {};
    bool ret = true;
    bool debugLog = false;


    for (auto &ch:str) {
        if ((ch == '[') || (ch == '{') || (ch == '('))  {
            brackets.push(ch);
        } else if ((ch == ']') || (ch == '}') || (ch == ')')) {
            if (debugLog) {
                cout << "Stack Top:" << brackets.top() << "Bracket :" << ch << endl;
            }
            if (brackets.empty()) {
                return false;
            }
            if (((brackets.top() == '[') && (ch == ']' )) ||
                ((brackets.top() == '{') && (ch == '}' ))  ||
                ((brackets.top() == '(') && (ch == ')' ))) {
                brackets.pop();
            } else {
                return false;
            }
        } else {
            /* nothing to do */
        }
    }

    if (brackets.empty()) {
        ret = true;
    } else {
        ret = false;
    }

    return ret;
}

void
test_balancedBrackets() {
    string str = "([])(){}(())()()";
    bool ret = balancedBrackets(str);

    cout << "Input" << endl;
    cout << str << endl;
    cout << "Output " << endl;
    if (ret == true) {
        cout << "Brackets are balanced in string: " << str << endl;
    } else {
        cout << "Brackets are not balanced in string: " << str << endl;
    }
}

#endif //GNU_BALACEDBRACKETS_H
