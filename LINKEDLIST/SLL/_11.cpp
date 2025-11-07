// Problem Statement: Given the heads of two singly linked-lists headA and headB, 
// return the node at which the two lists intersect. If the two linked lists have no intersection at all,
// return null.

// Example 1:
// Input:
// List 1 = [1,3,1,2,4], List 2 = [3,2,4]
// Output:
// 2
// Explanation: Here, both lists intersecting nodes start from node 2.
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data = data1 ;
        next=nullptr;
    }
};
Node* convertArrToLL(vector<int> arr){
    Node* head= new Node(arr[0]);
    Node *mover= head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i]);
        mover->next=temp;   
        mover=temp;
    }
    return head;   
}
void printLL(Node *head){
    Node* mover=head;
    // printing the linked list or traversing the linked list
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
    cout<<endl;
}
Node* intersectBrute(Node* head1,Node* head2){
    while(head2!=nullptr){
        Node*temp=head1;
        while(temp!=nullptr){
            if(temp==head2)return head2;
            temp=temp->next;
        }
        head2=head2->next;
    }
    return nullptr;
}
Node* intersectBetter(Node* head1,Node* head2){
    unordered_set<Node*>st;
    while(head1!=nullptr){
       st.insert(head1);
       head1=head1->next;
    }
    while(head2!=nullptr){
        if(st.find(head2)!=st.end())return head2;
        head2=head2->next;
    }
    return nullptr;
}
Node* intersectOptimal(Node* head1,Node* head2){
    Node* d1=head1;
    Node* d2=head2;
    while(d1!=d2){
        d1=d1==nullptr?head2:d1->next;
        d2=d2==nullptr?head1:d2->next;
    }
    return nullptr;
}
int main(){
       
    }
