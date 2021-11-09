//
// Created by kamr on 11/8/2021.
//

#ifndef GNU_TRIEST_H
#define GNU_TRIEST_H


class TrieNode {
public :
    static const int R = 256;
    // all other node will have value INT_MAX and leaf will have value
    int value;
    struct TrieNode *next[R];

    TrieNode() {
        for (int i = 0; i < R; i++) {
            next[i] = nullptr;
        }
        value = INT_MAX;
    }
};

class TrieST {
public:
    static const int R = 256;
    TrieNode *root;

    TrieST() {
        root = new TrieNode();
    }

    TrieNode*
    putInt(TrieNode *x, string key, int value, int d) {
        // if x is nullptr then we have to add node.
        if (x == nullptr) {
            x = new TrieNode();
        }
        // else we have already created node

        // we encounter leaf, we update the value and return
        if (d == key.length()) {
            x->value = value;
            return x;
        }

        // character at d
        char c = key[d];
        x->next[c] = putInt(x->next[c], key, value, d + 1);
        return x;
    }

    void
    put(string key, int value) {
        root = putInt(root, key, value, 0);
    }



    TrieNode*
    getInt(TrieNode *x, string key, int d) {
        // key does not exist
        if (x == nullptr) {
            return nullptr;
        }

        // we found leaf
        if (d == key.length()) {
            return x;
        }

        // we need to deeper
        char c = key[d];
        return getInt(x->next[c], key, d + 1);
    }

    int
    get(string key) {
        TrieNode *x = getInt(root, key, 0);
        if (x == nullptr) {
            return INT_MAX;
        }
        // we found the value
        return x->value;
    }

    bool
    contains(string key) {
        return (getInt(root, key, 0) != nullptr);
    }

    // collect all the keys with prefix in Q
    void
    collect(TrieNode *x, string prefix, vector<string> &q) {
       // node is null
        if (x == nullptr) {
            return;
        }
        if (x->value != INT_MAX ){
            q.push_back(prefix);
        }
        for (int c = 0; c < R; c++) {
            collect(x->next[c], prefix + 'c', q);
        }
    }

    void
    collect(TrieNode *x, string pre, string pat, vector<string> &q) {
        int d = pre.length();

        if (x == nullptr) {
            return;
        }
        // we visted all the value in pat
        if ((d == pat.length()) && (x->value != INT_MAX)) {
            q.push_back(pre);
        }

        if (d == pat.length()) {
            return;
        }
        //get next character in pattern
        char next = pat[d];
        for (int c = 0; c < R; c++) {
            if ((next == '.') || (next == 'c')) {
                collect(x->next[c], pre + 'c', pat, q);
            }
        }
    }

    vector<string>
    keysWithPrefix(string prefix) {
        vector<string> Q = {};
        TrieNode *x = getInt(root, prefix, 0);
        collect(x, prefix, Q);
        return Q;
    }

    vector<string>
    keys() {
        return keysWithPrefix("");
    }

    vector<string>
    keysThatMatch(string pattern) {
        vector<string> Q = {};
        collect(root, "", pattern, Q);
        return Q;
    }

    int
    search(TrieNode *x, string query, int d, int &len) {
        if (x == nullptr) return len;
        if (x->value != INT_MAX) { len  = d; }
        if (d == query.length()) {return len;}

        char c = query[d];
        return  search(x->next[c], query, d + 1, len);
    }

    string
    longestPrefixOf(string query) {
        int d = 0;
        int len = search(root, query, 0, d);
        return query.substr(0, len);
    }

    TrieNode* removeInt(TrieNode *x, string key, int d) {
        if (x == nullptr) { return nullptr; }
        if (d == key.length()) {
            x->value = INT_MAX;
        } else {
            char c = key[d];
            x->next[c] = removeInt(x->next[c], key, d + 1);
        }
        if (x->value != INT_MAX) {
            return x;
        }

        for (int c = 0; c < R; c++) {
            if (x->next[c] != nullptr)  {return x;}
        }
        return x;
    }

    void remove(string key) {
        root = removeInt(root, key, 0);
    }
};

/*
class TSTNode {
    char c;
    int value;
    TSTNode *left, *right, *mid;

    TSTNode() {
        left = right = mid = nullptr;
        value = INT_MAX;
    }
};

class TST {
    TSTNode *root;

    TST() {
        root = nullptr;
    }

    TSTNode *
    get(TSTNode *x, string key, int d) {
        // we could not find node
        if (x == nullptr) {
            return nullptr;
        }

        if (key.length() == d) {
            return x;
        }

        char c = key[d];
        return (x->next[c], key, d + 1);
    }


    int
    get(string key) {
        TSTNode *x = get(root, key, 0);
        if (x == nullptr) {
            return  INT_MAX;
        }
        return x->value;
    }

    bool
    contains(string key) {
        return (get(key) != nullptr);
    }

    TSTNode *
    put(TSTNode *node, string key, int value, int d) {
        if (node == nullptr) {
            node = new TSTNode();
            node->c = string[d];
        }

        char c = string[d];
        // node is greater
        if (c < node->c) {
            node->left = put(node->left, key, value, d + 1);
        } else if (c > node->c) {
            node->right = put(node->right, key, value, d + 1);
        } else if (d < key.length() - 1) {
            node->mid = put(node->mid, key, value, d + 1);
        } else {
            node->value = value;
        }
        return node;
    }

    void
    put(string key, int value) {
        root = put(root, key, value, 0);
    }
};
*/
void test_trie() {
    unordered_map<string, int> keyValPair = {{"abc", 4}, {"abcd", 5},
                                               {"raj kamal", 3},{"sonu", 8}};
    TrieST *trie = new TrieST();
    bool  ret;
    int val;
    string key;

    for (auto &entry:keyValPair) {
        trie->put(entry.first, entry.second);
    }

    cout << "------------------------------------------------";
    cout << "Input:" << endl;
    for (auto &entry:keyValPair) {
        cout<< entry.first << "--" << entry.second << endl;
    }
    cout << "Output" << endl;
    ret = false;
    key = "abc";
    val = trie->get(key);
    cout <<" Trie:" << key << "--" << val << endl;

    key = "make";
    val = trie->get(key);
    cout <<" Trie:" << key << "--" << val << endl;

}
#endif //GNU_TRIEST_H
