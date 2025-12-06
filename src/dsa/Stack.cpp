#include "dsa/Stack.hpp"

StackDS::StackDS() {}

void StackDS::push(int value) {
    arr.push_back(value);
}

void StackDS::pop() {
    if (!arr.empty())
        arr.pop_back();
}

int StackDS::top() {
    if (arr.empty()) return -1;
    return arr.back();
}

bool StackDS::isEmpty() {
    return arr.empty();
}

vector<int> StackDS::getAll() {
    return arr;
}
