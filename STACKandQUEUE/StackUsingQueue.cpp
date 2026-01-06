#include<bits/stdc++.h>
using namespace std;
class StackUsingQueue{
    queue<int> q1;
public:
    StackUsingQueue() {
    }
    void push(int val) {
        q1.push(val);
        int sz = q1.size();
        for(int i = 0; i < sz - 1; i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }
    void pop() {
        if(isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        q1.pop();
    }   
    int top() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Indicating stack is empty
        }
        return q1.front();
    }   
    bool isEmpty() {
        return q1.empty();
    }
    ~StackUsingQueue() {
        while(!isEmpty()) {
            pop();
        }
    }
};
int main(){
    StackUsingQueue stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout<<"Top element: "<<stack.top()<<endl; // Should print 30
    stack.pop();
    cout<<"Top element after pop: "<<stack.top()<<endl; // Should print 20
    stack.pop();
    stack.pop();
    stack.pop(); // Should indicate stack underflow
    return 0;
}