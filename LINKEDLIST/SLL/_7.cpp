// Problem Statement : Segregate even and odd nodes in LinkedList
// Given a LinkedList of integers. Modify the LinkedList in such a way that in Modified LinkedList all the even numbers appear before all the odd numbers in LinkedList.
// Also, note that the order of even and odd numbers should remain the same. 
// Example 1:
// Input: 1→2→3→4→5→6→Null
// Output: 2→4→6→1→3→5→Null

// Explanation : 
// Odd Nodes in LinkedList are 1,3,5 and 
// Even Nodes in LinkedList are 2,4,6
// In Modified LinkedList all even Nodes comes before 
// all Odd Nodes. So Modified LinkedList looks like 
// 2→4→6→1→3→5→Null. Order of even and odd Nodes is 
// maintained in modified LinkedList.
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
Node* oddevenBrute(Node* head){
    Node*temp =head;
    vector<int> arr;
    while(temp!=nullptr&&temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp)arr.push_back(temp->data);
    temp=head->next;
    while(temp!=nullptr&&temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp)arr.push_back(temp->data);
    int i=0;
    temp=head;
    while(temp!=nullptr){
        temp->data=arr[i++];
        temp=temp->next;
    }
    return head;
}
Node* oddevenOptimal(Node* head){
    Node* odd=head;
    Node*even=head->next;
    Node*evenhead=head->next;
    while(even!=nullptr&&even->next!=nullptr){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even =even->next;
    }
    odd->next=evenhead;
    return head;

}
int main(){
    vector<int> arr={1,2,3,4,5,6};
    Node* head= convertArrToLL(arr);
    printLL(head);
    cout<<endl;
    Node* temp=head;
    temp=oddevenBrute(temp);
    cout<<"brute"<<endl;
    printLL(temp);
    temp=head;
    cout<<"optim"<<endl;
    temp=oddevenOptimal(head);
    printLL(temp);
   

}

