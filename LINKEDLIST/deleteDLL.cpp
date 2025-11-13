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
Node* deleteHead(Node *head){
    if(head==nullptr||head->next==nullptr)return nullptr;
    Node *prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;    
}
Node* deleteTail(Node* head){
    if(head==nullptr||head->next==nullptr)return nullptr;
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    } 
    Node* prev=temp->back;
    temp->back=nullptr;
    delete temp;
    prev->next=nullptr;
    return head;
}
Node* deleteKthElement(Node *head , int k){
    if(head==nullptr)return nullptr;
    Node *temp=head;
    int cnt=0;
    while (temp!=nullptr)
    {
        cnt++;
       if(cnt==k)break;
        temp=temp->next;
    }
    Node*front=temp->next;
    Node*prev=temp->back;

    if(front==nullptr&&prev==nullptr){
        return nullptr;
    }else if(prev==nullptr){
       return deleteHead(head);
    }else if(front==nullptr){
       return  deleteTail(head);
        
    }
        prev->next=front;
        front->back=prev;
        temp->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return head;    
}
void deleteNode(Node* del){
    if(del==nullptr)return;
    if(del->next==nullptr&&del->back==nullptr){
        delete del;
        return;
    }
    Node* prev=del->back;
    Node* front=del->next;
    if(prev!=nullptr){
        prev->next=front;
    }
    if(front!=nullptr){
        front->back=prev;
    }
    del->next=nullptr;
    del->back=nullptr;
    delete del;
}
int main(){
    vector<int> arr={1,2,3};
    Node* head= convertArrToDLL(arr);
    // PrintDLL(head);
    // head=deleteHead(head);
    // PrintDLL(head);
    // PrintDLL(head);
    // head=deleteTail(head);
    // PrintDLL(head);
    // head=deleteKthElement(head,5);
    // PrintDLL(head);
    deleteNode(head->next->next);
    PrintDLL(head);
       
}