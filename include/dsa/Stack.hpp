#pragma once
#include <vector>
using namespace std;

class StackDS {
private:
    vector<int> arr;

public:
    StackDS();
    void push(int value);
    void pop();
    int top();
    bool isEmpty();
    vector<int> getAll();
};
