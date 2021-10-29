//
// Created by kamr on 10/27/2021.
//

#ifndef GNU_RUNLENGTHENCODING_H
#define GNU_RUNLENGTHENCODING_H

string
runLengthEncoding (string str) {
    char prev, s, ch;
    int count;
    vector<char> res;
    bool test = false;

    prev = str[0];
    count = 1;

    for (int i = 1; i < str.length(); i++) {
        if (test) {
            cout << str[i] << " ";
        }
        s = str[i];
        if (s == prev) {
            count++;
            if (count == 9) {
                ch  = '9';
                res.push_back(ch);
                res.push_back(prev);
                count = 0;
            }
        } else {
            if (count != 0) {
                ch = '0' + count;
                res.push_back(ch);
                res.push_back(prev);
            }
            prev = s;
            count = 1;
        }
    }

    if (count == 9) {
        ch  = '9';
    } else {
        ch = '0' + count;
    }
    res.push_back(ch);
    res.push_back(prev);


    if (test) {
        cout << endl;
    }
    return string (res.begin(), res.end());
}
void
test_runLengthEncoding() {
    string str;
    string res="";

    str ="AAAAAAAAAAAAABBCCCCDD";
    cout<< "Input: " << str << endl;
    res = runLengthEncoding(str);
    cout<< "Output: " << res << endl;

    str = "1";
    cout<< "Input: " << str << endl;
    res = runLengthEncoding(str);
    cout<< "Output: " << res << endl;

    str = "A";
    cout<< "Input: " << str << endl;
    res = runLengthEncoding(str);
    cout<< "Output: " << res << endl;

    str = "AA";
    cout<< "Input: " << str << endl;
    res = runLengthEncoding(str);
    cout<< "Output: " << res << endl;

    str = "  ";
    cout<< "Input: " << str << endl;
    res = runLengthEncoding(str);
    cout<< "Output: " << res << endl;

    str ="........______=========AAAA   AAABBBB   BBB";
    cout<< "Input: " << str << endl;
    res = runLengthEncoding(str);
    cout<< "Output: " << res << endl;



}
#endif //GNU_RUNLENGTHENCODING_H
