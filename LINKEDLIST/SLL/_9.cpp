// Problem Statement: Given the head of a linked list of integers, delete the middle node of the linked list
//  and return the modified head. However, if the linked list has an even number of nodes, 
// delete the second middle node.
// Input: 1->2->3->4->5 
// Output: 1->2->4->5

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

Node *deleteMiddleBrute(Node*head){
    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    temp=head;
    int mid=cnt/2;
    while(temp!=nullptr){
        mid--;
        if(mid==0){
            Node*middle=temp->next;
            temp->next=temp->next->next;
            delete middle;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node*deleteMiddleOptimal(Node* head){
    Node*slow=head;
    Node* fast=head->next;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node*middle=slow->next;
    slow->next=slow->next->next;
    delete middle;
    return head;
}
int main(){
        vector<int> arr={1,26,4,14,95,6};
         Node* head= convertArrToLL(arr);
         printLL(head);
         cout<<endl;
         cout<<"brute force:";
         Node*temp=deleteMiddleBrute(head);
         printLL(temp);
         head= convertArrToLL(arr);
         cout<<"optimal :";
         temp=deleteMiddleOptimal(head);
         printLL(temp);
}