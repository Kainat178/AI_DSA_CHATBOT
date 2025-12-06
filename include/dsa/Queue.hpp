#pragma once
#include <vector>
using namespace std;

class QueueDS {
private:
    vector<int> arr;
    int frontIndex;
    int rearIndex;

public:
    QueueDS();
    void enqueue(int value);
    void dequeue();
    int front();
    bool isEmpty();
    vector<int> getAll();
};
