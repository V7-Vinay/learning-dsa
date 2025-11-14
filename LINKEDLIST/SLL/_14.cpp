#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data = data1;
        next=nullptr;
    }
};
// converting a given array to linked list
Node* conveertArrToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover =head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    return head;
}
int lengthofLL(Node* head){
    int count=0;
    Node*headmover =head;
    while(headmover!=nullptr){
        count++;
        headmover=headmover-> next;
    }
    return count;
}

bool searchLL(Node* head,int key){
    Node* mover =head;
    while(mover!=nullptr){
        if(mover->data==key)return true;
        mover=mover->next;
    }
    return false;
}
void printLL(Node*head){
    Node* mover=head;
    // printing the linked list or traversing the linked list
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
}
Node* reverseOptimizedIterative(Node* head){
    Node*temp = head,*prev=nullptr;
    while(temp!=nullptr){
       Node* front=temp->next;
       temp->next=prev;
       prev=temp;
       temp=front;
    }
    return prev;
}
Node* kthnode(Node* temp,int  k){
    int count=1;
    while(temp!=nullptr&&count<k){
        temp=temp->next;
        count++;
    }
    return temp;
}
Node* kreverseLL(Node*head ,int k){
    Node* temp=head;
    Node* previous=nullptr;
    while(temp!=nullptr){
        Node* kth=kthnode(temp,k);
        if(kth==nullptr){
            if(previous)
            previous->next=temp;
            break;
        }
            Node *nextNode=kth->next;
            kth->next=nullptr;
            reverseOptimizedIterative(temp);
            if(temp==head){
                head=kth;
            }else{
                previous->next=kth;
            }
        previous=temp;
        temp=nextNode;
    }
    return head;
}
 int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head= conveertArrToLL(arr);
    Node* mover=head;
    printLL(head);
    cout<<endl;
    head=kreverseLL(head,4);
    printLL(head);  
    return 0;
}