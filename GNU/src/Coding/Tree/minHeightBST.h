//
// Created by kamr on 11/1/2021.
//

#ifndef GNU_MINHEIGHTBST_H
#define GNU_MINHEIGHTBST_H

/* Given Sorted array, create balanced BST */
/* use the binary search tech of BST */
void
minHeightBstHelper(vector<int> array, int start, int end, BST* node, int &count) {
    if ((start <= end) && (count <= array.size())) {
        mid = (start + end)/2;
        node->insert(array[mid]);
        count = count + 1;
        minHeightBstHelper(array, start, mid - 1, node);
        minHeightBstHelper(array, mid + 1 , end, node);
    }
}

BST *
minHeightBst(vector<int> array) {
    int start = 0;
    int end  = array.size() - 1;
    int mid = (start + end)/2;

    if (array.size() == 0) {
        return nullptr;
    }

    if (array.size() == 1) {
        BST *root = new BST(array[0]);
        return root;
    }
    int count = 1;
    BST *root = new BST(array[mid]);
    minHeightBstHelper(array, start, mid - 1, root, count);
    minHeightBstHelper(array, mid + 1, end, root, count);
    return root;
}
#endif //GNU_MINHEIGHTBST_H
