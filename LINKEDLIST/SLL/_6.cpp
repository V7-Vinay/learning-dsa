// Check if the given Linked List is Palindrome
// Example 1:
// Input Format:

// LL: 1  2  3  2  1
// output:true
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
bool isPalindromeBrute(Node* head){
    Node* temp=head;
    stack<int> st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(st.top()!=temp->data)return false;
        st.pop();
        temp=temp->next;
    }
    return true;
}
Node* reverse(Node* head){
     Node*temp = head,*prev=nullptr;
    while(temp!=nullptr){
       Node* front=temp->next;
       temp->next=prev;
       prev=temp;
       temp=front;
    }
    return prev;
}
bool isPalindromeOptimal(Node* head){
    Node*slow=head,*fast=head;
    while(fast->next!=nullptr&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node*newNode=reverse(slow);
    Node*first=head;
    Node* second=newNode;
    while(second->next){
        if(first->data!=second->data)return false;
        first=first->next;
        second=second->next;
    }
    reverse(newNode);
    return true;
}
int main(){
    vector<int> arr={1,2,3,4,5,6,5,4,3,2,1};
    Node* head= convertArrToLL(arr);
    printLL(head);
    cout<<endl;
    cout<<"the string is palindrome(brute):"<<isPalindromeBrute(head)<<endl;
    cout<<"the string is palindrome(optimal):"<<isPalindromeOptimal(head);
}