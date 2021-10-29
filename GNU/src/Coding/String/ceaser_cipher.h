//
// Created by kamr on 10/27/2021.
//

#ifndef GNU_CEASER_CIPHER_H
#define GNU_CEASER_CIPHER_H


string
caesarCypherEncryptor(string str, int key) {
    string s;
    char ch;
    int diff, add;
    bool test = false;
    key = key % 26;

    if (str.empty()) {
        return NULL;
    }


    for (auto c:str) {
        diff = 'z' - c;
        if (diff >= key) {
            ch = c + key;
        } else {
            add = key - diff;
            if (test) {
                cout << "add:" << add << " key:" << key << " diff:" << diff << endl;
            }
            /* -1 as i am including a already */
            ch = 'a' + add - 1;
        }
        s.push_back(ch);
    }
    return s;
}

void test_caesarCypherEncryptor()
{
    int key;
    string istr, ostr;

    istr = "xyz";
    key = 2;
    ostr =caesarCypherEncryptor(istr, key);
    cout << "Input: " << istr << " , Key=" << key << " Output:" << ostr << endl;

}

#endif //GNU_CEASER_CIPHER_H
