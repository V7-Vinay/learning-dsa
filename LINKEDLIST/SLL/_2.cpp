//given a linked list , we have to find the reverse of the linked list
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
Node* reverseBruteForce(Node* head){
    stack<int>st;
    Node*temp = head;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while (temp!=nullptr)
    {
        /* code */
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
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

Node* reverseOptimizedRecursive(Node* head){
    if(head==nullptr||head->next==nullptr)return head;
    Node*newNode = reverseOptimizedRecursive(head->next);
    Node* front=nullptr;
    front=head->next;
    front->next=head;
    head->next=nullptr;
    return newNode;
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
    vector<int> arr={1};
    Node* head= convertArrToLL(arr);
    cout<<"Original Linked List: ";
    printLL(head);
    cout<<endl;
    head=reverseBruteForce(head);
    cout<<"Reversed Linked List using Brute Force: ";
    printLL(head);
    cout<<endl;
    head= convertArrToLL(arr);
    head=reverseOptimizedIterative(head);
    cout<<"Reversed Linked List using Optimized Iterative: ";
    printLL(head);
    cout<<endl;
    head= convertArrToLL(arr);
    head=reverseOptimizedRecursive(head);
    cout<<"Reversed Linked List using Optimized Recursive: ";
    printLL(head);
    cout<<endl;
    return 0;
}