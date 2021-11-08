//
// Created by kamr on 11/3/2021.
//

#ifndef GNU_MINMAXSTACK_H
#define GNU_MINMAXSTACK_H

/*
 * Idea is to track minimum and maximum at every step. create a min array and max array and
 * keep track of min and max at that level
 */
class MinMaxStack {
private:
    vector<int> stack = {};
    vector<unordered_map<string, int>> minmaxstack = {};
public:
    int peek() {
        return stack[stack.size()- 1];
    }

    int pop() {
        int ret = stack[stack.size() - 1];
        minmaxstack.pop_back();
        stack.pop_back();
        return ret;
    }

    void push(int number) {
        stack.push_back(number);

        unordered_map<string, int> newMinMax =  {{"Min", number}, {"Max", number}};
        if (minmaxstack.size() > 0) {
            unordered_map<string, int> lastMinMax = minmaxstack[minmaxstack.size() - 1];
            newMinMax["Min"] = min(lastMinMax["Min"], number);
            newMinMax["Max"] = max(lastMinMax["Max"], number);
        }
        minmaxstack.push_back(newMinMax);
    }

    int getMin() {
        unordered_map<string, int> minV =  minmaxstack[minmaxstack.size() - 1];
        return minV["Min"];
    }

    int getMax() {
        unordered_map<string, int> maxV =  minmaxstack[minmaxstack.size() - 1];
        return maxV["Max"];
    }
};


#endif //GNU_MINMAXSTACK_H
