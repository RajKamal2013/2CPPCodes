//
// Created by kamr on 11/17/2021.
//

#ifndef GNU_PRAMP_H
#define GNU_PRAMP_H



#include <iostream>
#include <string>

/*-------------------------------------------- Decrypt ===============================================*/


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



using namespace std;

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
        } else {
            for (auto letter:alphabets) {
                tempValue = prevValue + letter;
                for (int idx = 0; idx <= 10; idx++) {
                    currValue = tempValue + (idx * 26);
                    if (char(currValue) == ch) {
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


int main() {
    string input = "dnotq";
    string output = decrypt(input);
    cout << "Decrypt of " << input << " is " << output << endl;
    return 0;
}




-------------------------------------------------------------------------------------------------------------------------------------

// Vmware organizes a conference and a good number of papers get published in the conference.
// All the participants in the conference are asked to rate the papers and must have to rate all the papers in the order
// For example if we have 4 papers - A, B, C, D
// So person needs to give unique rating to each paper so
// B-1
// A-2
// C-3
// D-4
// => BACD

// Now we need to build a calculator to calculate the people's choice rating, by considering the ratings given by each participants
// The ordering of paper is decided by who received the most 1st position ratings. If two or more papers tie in the first position,
// we consider the second position to resolve the conflict, if they tie again, we continue this process until the ties are resolved.
// If two or more papers are still tied after considering all positions, we rank them alphabetically based on their paper name.
// 4 participants
// Rating: "ABC","ACB","BAC","BCA",

// ABC

/*
pseudoCode
0. paperCount
1. for each currRank in paperCount
    find the maximum vote  and that is not yet accounted in output
    find the paper(s) which got maximum vote and that is not yet accounted in output - conflicts vector
    if only one paper got the maximum vote, the add to output
    else
      currRatingIndex = currRank + 1;
      while done is false && (currRatingIndex < paperCount) {
        newConflict --> vector
        minCount = 0;
        currRatingIndex = currRank + 1;
        for each  ch in conflicts vector {
          if currRatingIndex[ch] > minCount {
            newConflict.clear();
            newConflict.push_back(ch);
            minCount = currRating[ch];
          } else if (currRatingIndex[ch] == minCount) {
             newConflict.push_back(ch);
          }
        }
        if (newConflict.size() == 1) {
          done = true;
          output = output + ch;
          break;
        } else {
          conflict = newConflict;
          currRatingIndex = currRatingIndex + 1;
        }
      }
      if (!done) {
        minCh = CHAR_MAX;
        for (ch : conflicts) {
          if ch < minCh  {
            minCh = ch;
          }
        }
        output = output + minCh;
      }


-->
*/
string
ratingCalculater(vector<string> ratings) {
    bool dbgLog = false;
    if (ratings.size() == 0)  {
        return "";
    }
    if (ratings.size() == 1) {
        return ratings[0];
    }


    int paperCount = ratings[0].length();

    vector<unordered_map<char, int>> ratingsMap(paperCount);
    std::size_t found;

    int currRank = 0;
    vector<char> conflicts = {};
    vector<char> newConflicts = {};
    string output = "";
    int maxCount = 0;
    unordered_map<char, int> currMap = {};
    int currRatingIndex;
    bool done = false;
    int maxCount2 = 0;
    unordered_map<char, int> currHash = {};
    char ch, minCh;

    for (currRank = 0; currRank < paperCount; currRank++) {
        currMap = ratingsMap[currRank];
        for (auto str:ratings) {
            ch = str[currRank];

            if (currMap.find(ch) == currMap.end()) {
                currMap[ch] = 1;

            } else {
                currMap[ch] = currMap[ch] + 1;
            }
        }
        ratingsMap[currRank] = currMap;
    }

    if (dbgLog) {
        for (currRank = 0; currRank < paperCount; currRank++) {
            currMap = ratingsMap[currRank];
            cout << "mapIdx :" << currRank << endl;
            for (auto hash:currMap) {
                cout << "{" << hash.first << " " << hash.second << " }";
            }
            cout << endl;
        }
    }
    for (currRank = 0; currRank < paperCount; currRank++) {
        maxCount = 0;
        currMap = ratingsMap[currRank];
        done = false;

        for (auto hash:currMap) {
            ch = hash.first;
            found = output.find(ch);
            if (found == std::string::npos) {
                if (hash.second > maxCount) {
                    conflicts.clear();
                    conflicts.push_back(hash.first);
                    maxCount = hash.second;

                } else if (hash.second == maxCount) {
                    conflicts.push_back(hash.first);

                } else {
                    cout << __LINE__ << endl;
                }
            }
        }

        if (conflicts.size() == 1) {
            output = output + conflicts[0];
            done = true;
        }

        if (dbgLog) {
            cout << __LINE__ << " Conflicts: Size " << conflicts.size() << endl;
            for (auto ch:conflicts) {
                cout << ch << " ";
            }
            cout << endl;
        }


        currRatingIndex = currRank + 1;
        maxCount2 = 0;
        while ((!done) && (currRatingIndex < paperCount)) {
            newConflicts.clear();
            maxCount2 = 0;
            currHash = ratingsMap[currRatingIndex];
            if (dbgLog) {
                cout << __LINE__ << " Conflicts: Siz " << conflicts.size() << endl;
                for (auto ch:conflicts) {
                    cout << ch << " ";
                }
                cout << endl;
            }
            for (auto ch:conflicts) {
                if (currHash[ch] > maxCount2) {
                    newConflicts.clear();
                    newConflicts.push_back(ch);
                    maxCount2 = currHash[ch];
                } else if (currHash[ch] == maxCount2) {
                    newConflicts.push_back(ch);
                }
            }

            if (newConflicts.size() == 1) {
                done = true;
                output = output + ch;

                if (dbgLog) {
                    cout << __LINE__ << " Char : "<< conflicts[0] << "Output" << output << endl;
                }
            } else {
                conflicts = newConflicts;
                currRatingIndex = currRatingIndex + 1;
            }
        }


        if (!done) {
            minCh = CHAR_MAX;
            for (auto ch : conflicts) {
                if (ch < minCh)  {
                    minCh = ch;
                }
            }
            output = output + minCh;

            if (dbgLog) {
                cout << __LINE__ << " No Resolution: Char : "<< conflicts[0] << " Output" << output << endl;
            }
        }
    }
    return output;
}

void
test_ratingCalculator() {
    vector<string> ratings  ={"ACB","CAB","CBA","BAC","BCA","ABC"};
    for (auto str:ratings) {
        cout << str << " ";
    }
    cout << endl;
    string output = ratingCalculater(ratings);
    cout << output << endl;
}



// "ACB","CAB","CBA","BAC","BCA","ABC"
// ABC





--------------------------------------------------------------------------------------------------------------------------------------

/* TinyUrl  */


class TinyUrl
{
    unordered_map<string, string> hashTable;
    int modulo;
    int monotonicallyIncreasingNumber;
public:
    TinyUrl() {
        modulo = 23;
        monotonicallyIncreasingNumber = 0;
        hashTable = {};
    }

    string
    Compress(string url, int userId) {
        string orig_url =url;
        url = url + to_string(userId);
        int hash;
        string hashStr ="";
        url = url + to_string(userId);
        for (char ch:url) {
            hash = ((hash * 10) + ch )% modulo;
        }
        hashStr = to_string(hash);
        if (hashTable.find(hashStr) != hashTable.end()) {
            string val = hashTable.find(hashStr)->second;
            if (val == orig_url) {
                return hashTable.find(hashStr)->first;
            } else {
                string temp = hashStr;
                monotonicallyIncreasingNumber++;
                hashStr = temp + to_string(monotonicallyIncreasingNumber);
                while (hashTable.find(hashStr) != hashTable.end()) {
                    monotonicallyIncreasingNumber++;
                    hashStr = temp + to_string(monotonicallyIncreasingNumber);
                }
                hashTable.insert({hashStr, orig_url});
                return hashStr;
            }
        } else {
            hashTable.insert({hashStr, orig_url});
            return hashStr;
        }
    }

    string
    deCompress(string hashStr) {
        if (hashTable.find(hashStr) == hashTable.end()) {
            cout << "No hash Find" << endl;
            return nullptr;
        } else {
            return hashTable.find(hashStr)->second;
        }

    }
};

void
test_tinyURL() {
    TinyUrl *app = new TinyUrl();
    string key = app->Compress("www.vmware.com", 11);
    cout << "key for www.vmware.com with user Id 11:" << key << endl;
    cout << "value for the key" << app->deCompress(key) << endl;
    free(app);
}



/*-------------------------------------------------------------------------------------------------------------*/

// can it be palindrome

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

/*-------------------------------------------------------------------------------------------------*/
#endif //GNU_PRAMP_H
