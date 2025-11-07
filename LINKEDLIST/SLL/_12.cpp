// Problem Statement: Given the head of a singly linked list representing a positive integer number. 
// Each node of the linked list represents a digit of the number,
//  with the 1st node containing the leftmost digit of the number and so on. 
//  The task is to add one to the value represented by the linked list and 
//  return the head of a linked list containing the final value

//  Input: 9->9->9
// Output: 1->0->0->0
// Explanation: 999 + 1 = 1000
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
Node* addOneIterative(Node* head){
    head= reverse(head);
    Node* current=head;
    int carry =1;
    while(current && carry){
        int sum=carry+current->data;
        current->data=sum%10;
        carry=sum/10;
        if(carry==0)break;
        if(!current->next&&carry){
            current->next=new Node(carry);
            carry=0;
        }
        current=current->next;
    }
    head=reverse(head);
    return head;
}
int addHelper(Node *node){
    if(!node)return 1;
    int carry=addHelper(node->next);
    int sum=node->data+carry;
    node->data=sum%10;
    return sum/10;
}
Node* addOneRecursive(Node* head){
    int carry=addHelper(head);
    if(carry){
        Node*newNode=new Node(carry,head);
        head=newNode;
    }
    return head;
}
int main(){
        vector<int> arr={9,9};
         Node* head= convertArrToLL(arr);
         printLL(head);
         cout<<"iterative addition :";
         Node*temp= addOneIterative(head);
         printLL(temp);
         head=convertArrToLL(arr);
         printLL(head);
         cout<<"recursive addition :";
          Node*temp1=addOneRecursive(head);
         printLL(temp1);
}