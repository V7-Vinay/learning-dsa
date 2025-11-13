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
Node* insertAtHead(Node *head,int data){
    Node*newNode = new Node(data,head,nullptr);
    head->back=newNode;
    return newNode;
}
Node * insertAtTail(Node* head,int data){
    if(head==nullptr){
        return insertAtHead(head,data);
    }
    Node* temp=head;
while(temp->next!=nullptr){
    temp=temp->next;
    }
    Node *newNode =new Node(data,nullptr,temp);
    temp->next=newNode;
    return head;
}
Node * insertBeforeTail(Node* head,int data){
    Node* temp=head;
    if(head->next==nullptr){
        return insertAtHead(head,data);
    }
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(data,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;
}
Node* insertBeforeKthElement(Node *head , int k,int data){
    Node* temp=head;
    int cnt=0;
    if(k==1){
        return insertAtHead(head,data);
    }
    while(temp!=nullptr){
        cnt++;
       if(cnt==k)break;
       temp=temp->next;
    }
    Node*prev=temp->back;
    Node * newNode=new Node(data,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;
}   
Node * insertBeforeNode(Node *someNode ,int data){
    Node* prev=someNode->back;
    Node* newNode=new Node(data,someNode,prev); 
    prev->next=newNode;
    someNode->back=newNode;   
}
    int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head= convertArrToDLL(arr);
    PrintDLL(head);
//     head=insertAtHead(head,0);
//     PrintDLL(head);
//     head=insertAtTail(head,6);
//     PrintDLL(head);
//     head=insertBeforeTail(head,9);
//     PrintDLL(head);  
    head=insertBeforeKthElement(head,2,10);
    PrintDLL(head);
 }