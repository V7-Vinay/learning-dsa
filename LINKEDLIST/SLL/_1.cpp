// // Given the head of a linked list of integers, 
// determine the middle node of the linked list. However, if the linked list has an even number of nodes,
//  return the second middle node
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
Node* findMedianBruteForce(Node* head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    int mid=cnt/2+1;
    temp=head;
    while(temp!=nullptr){
        mid=mid-1;
        if(mid==0)break;
        temp=temp->next;
    }
    return temp;
}

Node* findMedianOptimized(Node* head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    Node* fast=head;
    Node* slow=head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
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
}
int main(){
    vector<int> arr={1,2,3,4,5,6};
    Node* head= convertArrToLL(arr);
    printLL(head);
    cout<<endl;
    Node* medianNode=findMedianBruteForce(head);
    cout<<"Median Node using Brute Force: "<<medianNode->data<<endl;
    Node* medianNodeOpt=findMedianOptimized(head);
    cout<<"Median Node using Optimized Approach: "<<medianNodeOpt->data<<endl;
    return 0;
}   
