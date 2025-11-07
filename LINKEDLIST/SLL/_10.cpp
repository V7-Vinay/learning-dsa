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
Node* merge(Node* list1,Node *list2){
        Node* dummy = new Node(-1);
        Node* temp=dummy;
        while(list1&&list2){
            if(list1->data<=list2->data){
                temp->next=list1;
                list1=list1->next;
            }else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
            if(list1==nullptr){
                temp->next=list2;
            }else{
                temp->next=list1;
            }
        
        return dummy->next;
    }
    Node* middle(Node* head){
        Node* slow=head;
        Node* fast=head;
        fast=fast->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* sortListoptimal(Node* head) {
        if(head==nullptr||head->next==nullptr)return head;
        Node* temp=head;
        if(temp->next==nullptr)return temp;
        Node* center=middle(temp);
        Node* right=center->next;
        Node* left=head;
        center->next=nullptr;
        left=sortListoptimal(left);
        right=sortListoptimal(right);
        return merge(left,right);
    }
    Node* sortlistbrute(Node* head){
         Node* temp=head;
         vector<int>arr;
         while(temp){
            arr.push_back(temp->data);
            temp=temp->next;
         }
         sort(arr.begin(),arr.end());
        int i;
        temp=head;
        for(i=0;i<arr.size();i++){
            temp->data=arr[i];
            temp=temp->next;
        }
        return head;
    }
    int main(){
         vector<int> arr={1,26,4,14,95,6};
         Node* head= convertArrToLL(arr);
         printLL(head);
         cout<<endl;
         Node* temp=head;
         cout<<"optimal::";
         temp=sortListoptimal(temp);
         printLL(temp);
         temp=head;
         cout<<"brute::";
         temp=sortlistbrute(temp);
         printLL(temp);
    }