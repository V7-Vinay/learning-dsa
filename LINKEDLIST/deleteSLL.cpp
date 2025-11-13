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
Node* deleteHead(Node* head){
    if(head==nullptr)return head;
    Node*temp=head;
    head=head->next;
    free(temp);
    return head;    
}
Node* deleteTail(Node *head){
    if(head==nullptr||head->next==nullptr)return nullptr;
    Node* mover=head;
    while(mover->next->next!=nullptr){
        mover=mover->next;
    }
    free(mover->next);
    mover->next=nullptr;
    return head;    
}
Node *deleteNodeK(Node* head ,int k){
    if(head==nullptr)return head;
    Node* temp=head,*prev=nullptr;
    if(k==1){
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
        return head;
}

Node* deleteNodeValue(Node *head ,int value){
   if(head==nullptr)return head;
    Node* temp=head,*prev=nullptr;
    if(head->data==value){
        head=head->next;
        free(temp);
        return head;
    }
    while(temp!=nullptr){
        if(temp->data==value){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
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
    // head=deleteTail(head);   delete tail
    // printLL(head);
    // cout<<endl;
    // head=deleteHead(head);    delete head 
    // printLL(head);
    // cout<<endl; 
    // head=deleteNodeK(head,3);      // delete kth node
    // printLL(head);
    // cout<<endl; 
    head=deleteNodeValue(head,4);   // delete node with given value
    printLL(head);  
    cout<<endl;
    return 0;
}

