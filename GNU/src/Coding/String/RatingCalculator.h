//
// Created by kamr on 11/17/2021.
//

#ifndef GNU_RATINGCALCULATOR_H
#define GNU_RATINGCALCULATOR_H


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
 * pseudoCode
0. paperCount
1. for each currRank in paperCount
    find the maximum vote  and that is not yet accounted in output
    find the paper(s) which got maximum vote and that is not yet accounted in output - conflicts vector
    if only one paper got the maximum vote, the add to output
    else /// we go to resolve conflict by looking for conflict character ranks in furthers ranks
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
 */

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;


string
ratingCalculater (vector<string> ratings) {
    bool dbgLog = false;
    if (ratings.size() == 0) {
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
            if (dbgLog) {
                cout << __LINE__ << " No Conflict: Char : " << conflicts[0] << " Output" << output << endl;
            }
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
                    cout << __LINE__ << "Conflict Resolved: Char : " << conflicts[0] << "Output" << output << endl;
                }
            } else {
                conflicts = newConflicts;
                currRatingIndex = currRatingIndex + 1;
            }
        }


        if (!done) {
            minCh = CHAR_MAX;
            for (auto ch : conflicts) {
                if (ch < minCh) {
                    minCh = ch;
                }
            }
            output = output + minCh;

            if (dbgLog) {
                cout << __LINE__ << " No Resolution: Char : " << conflicts[0] << " Output" << output << endl;
            }
        }
    }
    return output;
}

void
test_ratingCalculator () {
    vector<string> ratings = {"ACB", "CAB", "CBA", "BAC", "BCA", "ABC"};
    for (auto str:ratings) {
        cout << str << " ";
    }
    cout << endl;
    string output = ratingCalculater(ratings);
    cout << output << endl;
}

#endif //GNU_RATINGCALCULATOR_H
