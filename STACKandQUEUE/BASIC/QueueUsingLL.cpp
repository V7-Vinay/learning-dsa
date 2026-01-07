#include<bits/stdc++.h>
using namespace std;
class QueueUsingLinkedList{
    struct Node{
        int data;
        Node* next;
        Node(int val){
            data=val;
            next=NULL;
        }
    };
    Node* frontNode;
    Node* rearNode;
public:
    QueueUsingLinkedList(){
        frontNode=NULL;
        rearNode=NULL;
    }
    void enqueue(int val){
        Node* newNode=new Node(val);
        if(rearNode==NULL){
            frontNode=rearNode=newNode;
            return;
        }
        rearNode->next=newNode;
        rearNode=newNode;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        Node* temp=frontNode;
        frontNode=frontNode->next;
        if(frontNode==NULL){
            rearNode=NULL;
        }
        delete temp;
    }
    int front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1; // Indicating queue is empty
        }
        return frontNode->data;
    }
    bool isEmpty(){
        return frontNode==NULL;
    }
    ~QueueUsingLinkedList(){
        while(!isEmpty()){
            dequeue();
        }
    }

};
int main(){
    QueueUsingLinkedList queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout<<"Front element: "<<queue.front()<<endl; // Should print 10
    queue.dequeue();
    cout<<"Front element after dequeue: "<<queue.front()<<endl; // Should print 20
    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); // Should indicate queue underflow
    return 0;
}