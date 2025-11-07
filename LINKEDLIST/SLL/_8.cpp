// Problem Statement: Given a linked list and an integer N, the task is to delete the Nth node 
// from the end of the linked list and print the updated linked list.

// Input:  5->1->2, N=2
// Output: 5->2
// Explanation: The 2nd node from the end of the linked list is 1.
//  Therefore, we get this result after removing 1 from the linked list.
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

Node *deleteNthNodeFromBackBrute(Node *head,int n){
    if(head==nullptr)return nullptr;
   Node* temp=head;
   int cnt=0;
   while(temp!=nullptr){
    cnt++;
    temp=temp->next;
   }
   if(cnt==n){
    Node* newNode=head->next;
    delete head;
    return newNode;
   }
   temp=head;
   while(temp!=nullptr){
    cnt--;
    if(cnt==n){break;}
    temp=temp->next;
   }
   Node*deleteNode =temp->next;
   temp->next=temp->next->next;
   delete deleteNode;

   return head;
}
Node* deleteNthNodeFromBackOptimal(Node * head,int n){
    Node* dummy = new Node(0, head);

        Node* slow = dummy;
        Node* fast = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return dummy->next;

   return head;

}
int main(){
         vector<int> arr={1,26,4,14,95,6};
         Node* head= convertArrToLL(arr);
         printLL(head);
         cout<<endl;
         cout<<"brute force:";
         Node* temp=deleteNthNodeFromBackBrute(head,1);
         printLL(temp);
         head= convertArrToLL(arr);
         cout<<"optimal:";
         Node* temp1=deleteNthNodeFromBackOptimal(head,1);
         printLL(temp1);
         
}