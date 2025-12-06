#include <iostream>
#include "dsa/Queue.hpp"
using namespace std;

int main() {
    QueueDS q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.front() << "\n"; // expect 10
    q.dequeue();
    cout << q.front() << "\n"; // expect 20
    auto all = q.getAll();
    for (int v : all) cout << v << " ";
    cout << "\n";
    q.dequeue(); q.dequeue();
    cout << q.isEmpty() << "\n"; // expect 1
    return 0;
}
