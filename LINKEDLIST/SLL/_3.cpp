// detecting a cycle in a linked list using Floyd’s Cycle-Finding Algorithm
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
bool isCyclePresentBruteForce(Node* head){
    Node* temp=head;
    unordered_map<Node*,int>map;
    while(temp!=nullptr){
        if(map.find(temp)!=map.end()){
            return true;
        }
        map[temp]=1;
        temp=temp->next;
    }
    return false;
}

bool isCyclePresentOptimized(Node* head){
    Node* slow=head;
    Node* fast=head;
while(fast&&fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast)return true;
}   
return false;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head= convertArrToLL(arr);
    // creating a cycle for testing
     // head->next->next->next->next->next=head->next;
    // printLL(head);
    cout<<"Is cycle present (Brute Force): ";
    cout<<isCyclePresentBruteForce(head)<<endl;
    cout<<"Is cycle present (Optimized): ";
    cout<<isCyclePresentOptimized(head)<<endl;
    return 0;
}
