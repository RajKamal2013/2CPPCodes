//
// Created by kamr on 11/11/2021.
//

#ifndef GNU_TINYURL_H
#define GNU_TINYURL_H

#include <unordered_map>
#include <string>
using namespace std;

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
#endif //GNU_TINYURL_H
