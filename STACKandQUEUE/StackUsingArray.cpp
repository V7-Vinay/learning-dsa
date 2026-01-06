#include<bits/stdc++.h>
using namespace std;
class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(int totalsize){
        data = new int[totalsize];
        nextIndex = 0;
        capacity = totalsize;
    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(int element){
        if(nextIndex == capacity){
            cout << "Stack is full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return data[nextIndex - 1];
    }
};
int main(){
    StackUsingArray s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl; // 30
    cout << "Stack size: " << s.size() << endl; // 3
    cout << "Popped element: " << s.pop() << endl; // 30
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // No
    return 0;
}