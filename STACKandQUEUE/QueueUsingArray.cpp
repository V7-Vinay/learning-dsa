#include<bits/stdc++.h>
using namespace std;
class QueueUsingArray{
    int *data;
    int frontIndex;
    int nextIndex;
    int capacity;
    int currentSize;

    public:
    QueueUsingArray(int totalsize){
        data = new int[totalsize];
        frontIndex = -1;
        nextIndex = 0;
        capacity = totalsize;
        currentSize = 0;
    }

    int size(){
        return currentSize;
    }

    bool isEmpty(){
        return currentSize == 0;
    }

    void enqueue(int element){
        if(currentSize == capacity){
            cout << "Queue is full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if(frontIndex == -1){
            frontIndex = 0;
        }
        currentSize++;
    }

    int dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        int result = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
        if(currentSize == 0){
            frontIndex = -1;
            nextIndex = 0;
        }
        return result;
    }

    int front(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return data[frontIndex];
    }
};
int main(){
    QueueUsingArray q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.front() << endl; // 10
    cout << "Queue size: " << q.size() << endl; // 3
    cout << "Dequeued element: " << q.dequeue() << endl; // 10
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // No
    return 0;
}
