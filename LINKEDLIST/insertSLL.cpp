#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val, Node *next1){
        data=val;
        next=next1;
    }
    Node(int val){
        data=val;
        next=NULL;
    }
};
Node* insertAtHead(Node *head,int value){
    // Node* temp = new Node(value); or
     Node* temp= new Node(value , head);
     return temp;
    // temp->next= head ;
    // head= temp;
    // return head;
}
Node* insertAtLast(Node* head ,int value){
    Node* temp=head;
    if(temp==nullptr){
        Node* newNode= new Node(value);
        return newNode;
    }
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* newNode= new Node(value);
    temp->next=newNode;
    return head;
}

Node* insertAtPosition(Node* head ,int k, int value){
   if(head==nullptr){
    if(k==1){
        return new Node(value);
    }else{
        return head;
    }
   }
    if(k==1){
        head=new Node(value,head);
        return head;
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k-1){
            Node* newNode =new Node(value);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
return head;
}

Node* insertBeforeValue(Node* head , int key ,int value){
   if(head==nullptr){
    return head;
   }
    if(head->data==key){
        head=new Node(value,head);
        return head;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        if(temp->next->data==key){
            Node* newNode =new Node(value);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
return head;
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
    vector<int> arr={1,2,3,4,5};
    Node* head= convertArrToLL(arr);
    printLL(head);
    cout<<endl;
    head=insertAtHead(head,0);
    printLL(head);
    cout<<endl;
    head=insertAtLast(head,6);
    printLL(head);
    cout<<endl;
    head=insertAtPosition(head,8,100);
    printLL(head);
    cout<<endl;
    head=insertBeforeValue(head,3,200);
    printLL(head);
    cout<<endl;
    return 0;
}

