#include<bits/stdc++.h>
using namespace std;
class QueueUsingStack {
    stack<int> s1, s2;
public:
    // Enqueue operation
    void enqueue(int x) {
        s1.push(x);
    }
    // Dequeue operation
    int dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            throw runtime_error("Queue is empty");
        }
        int front = s2.top();
        s2.pop();
        return front;
    }
    // Check if the queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
    // Get the front element of the queue
    int front() {   
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            throw runtime_error("Queue is empty");
        }
        return s2.top();
    }
    // Get the size of the queue
    int size() {
        return s1.size() + s2.size();
    }   
};
int main() {
    QueueUsingStack q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.front() << endl; // Output: 10
    cout << "Dequeue: " << q.dequeue() << endl;     // Output: 10
    cout << "Front element: " << q.front() << endl; // Output: 20
    cout << "Queue size: " << q.size() << endl;     // Output: 2
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Output: No
    return 0;
}