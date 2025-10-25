// detecting a cycle in a linked list using Floyd’s Cycle-Finding Algorithm and returning the length of the loop
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
int isCyclePresentBruteForce(Node* head){
    Node* temp=head;
    unordered_map<Node*,int>map;
    int timer=0;
    while(temp!=nullptr){
        if(map.find(temp)!=map.end()){
            cout<<timer<<"-"<<map[temp]<<":";
            return timer-map[temp];
        }
        map[temp]=timer;
        temp=temp->next;
        timer++;

    }
    return 0;
}

int isCyclePresentOptimized(Node* head){
    Node* slow=head;
    Node* fast=head;
while(fast&&fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        fast=slow->next;
        int timer=1;
        while (slow!=fast)
        {
         timer++;
         fast=fast->next;
        }
        return timer;
    }
}   
return 0;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head= convertArrToLL(arr);
    // creating a cycle for testing
     head->next->next->next->next->next=head->next;

    // printLL(head);
   cout<<"the length of the loop:"<<isCyclePresentBruteForce(head)<<endl;
   cout<<"the length of the loop:"<<isCyclePresentOptimized(head);
    return 0;
}
