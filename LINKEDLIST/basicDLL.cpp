#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
class Node{
    public:
    int data;
    Node* next;
    Node *back;
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data = data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* convertArrToDLL(vector<int> arr){
    Node *head=new Node(arr[0]);
    Node *prev=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void PrintDLL(Node* head){
    Node* temp=head;
    while(temp->next!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
Node * reverseDLL(Node* head){

    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* prev=nullptr;
    Node* current =head;
    while(current !=nullptr){
        prev=current->back;current->
        back=current->next;
        current->next=prev;
        current=current->back;
    }
    return prev->back;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head= convertArrToDLL(arr);
    PrintDLL(head);
    head=reverseDLL(head);
    PrintDLL(head); 
}