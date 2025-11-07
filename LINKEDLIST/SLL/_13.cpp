 // Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// Input Format: 
// (Pointer/Access to the head of the two linked lists)
// num1  = 243, num2 = 564
// l1 = [2,4,3]
// l2 = [5,6,4]

// Result: sum = 807; L = [7,0,8]
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
void printLLForward(Node* head) {
    if (head == nullptr) return;
    printLLForward(head->next);
    cout << head->data << " ";
}


Node* adders(Node* l1,Node*l2){
    Node* dummy=new Node(0);
    Node*temp=dummy;
    int carry =0;
    while(l1||l2||carry){
        int sum=0;
        if(l1){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node*newNode=new Node(sum%10);
        temp->next=newNode;
        temp=newNode;
    }
     return dummy->next;
}
int main(){
         vector<int> arr1={0,9,3};
         Node* head1= convertArrToLL(arr1);
         cout<<"given reversed number 1 : ";
         printLL(head1);
         cout<<"actual number 1 : ";
         printLLForward(head1);
         cout<<endl;
         vector<int> arr2={2,9};
         Node* head2= convertArrToLL(arr2);
         cout<<"given reversed number 2 : ";
         printLL(head2);
         cout<<"actual number 2 : ";
         printLLForward(head2);
         cout<<endl;
         Node* temp=adders(head1,head2);
         cout<<"the addition of the two number is : ";
         printLLForward(temp);
}