//
// Created by kamr on 10/31/2021.
//

#ifndef GNU_NODEHEIGHTS_H
#define GNU_NODEHEIGHTS_H


void
nodeheight_int(BST *node, int height, vector<int> &res) {
    if (node) {
        bool test = true;
        if (test) {
            cout << __LINE__ << " ->" << "Height " << height << " - " << "Node " << "-" << node->value << endl;
        }
        res.push_back(height);
        height = height + 1;
        nodeheight_int(node->left, height, res);
        nodeheight_int(node->right, height, res);
    }
}

int
nodeheight(BST *root) {
    bool test = true;
    if (root == nullptr) {
        return -1;
    }

    vector<int> res;
    int height = 0;

    nodeheight_int(root, height, res);
    int sum = 0;
    for (auto &data:res) {
        sum = sum + data;
    }
    sum = sum;

    if (test) {
        cout << __LINE__ << "->" << "Height Array" << endl;
        for (auto &data:res) {
            cout << data << " ";
        }
        cout << endl;

        cout << "Node Height : " << sum << endl;
    }
    return height;
}


void test_nodeHeights() {
    BST *root = new BST(10);
    vector<int> list = {5, 3, 8, 12, 11, 15, 13, 17};
    for (auto &data:list) {
        root->insert(data);
    }

    vector<int> res;
    int ret;

    ret = nodeheight(root);
    cout << "Node Heights " << ret << endl;

    cout << endl;
}
#endif //GNU_NODEHEIGHTS_H
