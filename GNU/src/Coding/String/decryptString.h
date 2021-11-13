//
// Created by kamr on 11/13/2021.
//

#ifndef GNU_DECRYPTSTRING_H
#define GNU_DECRYPTSTRING_H

#include <iostream>
#include <string>

using namespace std;


/*
 * dnotq -> crime
 *
 * An infamous gang of cyber criminals named “The Gray Cyber Mob”,
 * which is behind many hacking attacks and drug trafficking, has
 * recently become a target for the FBI. After intercepting some of
 * their messages, which looked like complete nonsense, the agency
 * learned that they indeed encrypt their messages, and studied their
 * method of encryption.
 *
 * Their messages consist of lowercase latin letters only, and every word
 * is encrypted separately as follows:
 * Convert every letter to its ASCII value. Add 1 to the first letter,
 * and then for every letter from the second one to the last one, add
 * the value of the previous letter. Subtract 26 from every letter until
 * it is in the range of lowercase letters a-z in ASCII.
 * Convert the values back to letters.
 * For instance, to encrypt the word “crime”
 * Decrypted message:	c	r	i	m	e
 * Step 1:	            99	114	105	109	101
 * Step 2:	            100	214	319	428	529
 * Step 3:	            100	110	111	116	113
 * Encrypted message:	d	n	o	t	q
 * The FBI needs an efficient method to decrypt messages.
 * Write a function named decrypt(word) that receives a string
 * that consists of small latin letters only, and returns the decrypted word.
 * Explain your solution and analyze its time and space complexities.
 *  (x + prevSum) - k*26 = X
 * input:  word = "dnotq"
 * output: "crime"
 *
 * input:  word = "flgxswdliefy"
 * output: "encyclopedia"
 */
string decrypt( const string& word )
{
    if (word == "") {
        return "";
    }

    string output = "";
    int currValue = 0;
    int prevValue = 0;
    int tempValue = 0;
    int currIdx = 0;
    string alphabets ="abcdefghijklmnopqrstuvwxyz";
    bool found = false;


    for (auto ch:word) {
        // convert first by adding previous value
        if (currIdx == 0) {
            currValue = ch - 1;
            output = output + char(currValue);
            prevValue = ch;
            currIdx = currIdx + 1;
        } else {

            for (auto letter:alphabets) {
                tempValue = prevValue + letter;
                for (int idx = 0; idx <= 10; idx++) {
                    currValue = tempValue - (idx * 26);
                    if (currValue == ch) {

                        prevValue = currValue;
                        output  = output + letter;
                        found = true;
                        break;
                    }
                }
                if (found) {
                    found = false;
                    break;
                }
            }
            currIdx = currIdx  + 1;
        }
    }
    return output;
}


void
test_decrypt() {
    string input = "dnotq";
    string output = decrypt(input);
    cout << "Decrypt of " << input << " is " << output << endl;
    input = "flgxswdliefy";
    output = decrypt(input);
    cout << "Decrypt of " << input << " is " << output << endl;
}

#endif //GNU_DECRYPTSTRING_H
