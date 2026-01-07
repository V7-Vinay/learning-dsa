#include<bits/stdc++.h>
using namespace std;
class StackUsingLinkedList{
    struct Node{
        int data;
        Node* next;
        Node(int val){
            data=val;
            next=NULL;
        }
    };
    Node* topNode;
public:
    StackUsingLinkedList(){
        topNode=NULL;
    }
    void push(int val){
        Node* newNode=new Node(val);
        newNode->next=topNode;
        topNode=newNode;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* temp=topNode;
        topNode=topNode->next;
        delete temp;
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1; // Indicating stack is empty
        }
        return topNode->data;
    }
    bool isEmpty(){
        return topNode==NULL;
    }
    ~StackUsingLinkedList(){
        while(!isEmpty()){
            pop();
        }
    }
};
int main(){
    StackUsingLinkedList stack;
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