#include "dsa/Queue.hpp"

QueueDS::QueueDS() : frontIndex(0), rearIndex(0) {}

void QueueDS::enqueue(int value) {
    arr.push_back(value);
    rearIndex++;
}

void QueueDS::dequeue() {
    if (!isEmpty())
        frontIndex++;
}

int QueueDS::front() {
    if (isEmpty()) return -1;
    return arr[frontIndex];
}

bool QueueDS::isEmpty() {
    return frontIndex == rearIndex;
}

vector<int> QueueDS::getAll() {
    return vector<int>(arr.begin() + frontIndex, arr.begin() + rearIndex);
}
