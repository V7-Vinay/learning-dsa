#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data = data1;
        next=nullptr;
    }
};
// converting a given array to linked list
Node* conveertArrToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover =head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    return head;
}
int lengthofLL(Node* head){
    int count=0;
    Node*headmover =head;
    while(headmover!=nullptr){
        count++;
        headmover=headmover-> next;
    }
    return count;
}

bool searchLL(Node* head,int key){
    Node* mover =head;
    while(mover!=nullptr){
        if(mover->data==key)return true;
        mover=mover->next;
    }
    return false;
}
void printLL(Node*head){
    Node* mover=head;
    // printing the linked list or traversing the linked list
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
}
 int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head= conveertArrToLL(arr);
    Node* mover=head;
    printLL(head);
    cout<<endl;
    cout<<"the length of linked list is "<<lengthofLL(head)<<endl;
    int key=9;
    if(searchLL(head,key)){
        cout<<"key is present in the linked list"<<endl;
    }else{
        cout<<"key is not present in the linked list"<<endl;
    }
    return 0;
}