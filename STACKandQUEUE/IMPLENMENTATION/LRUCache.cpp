#include<bits/stdc++.h> 
using namespace std;
class LRUCache {
public:


    class Node{
        public:
        int key;
        int val;
        Node *prev;
        Node*next;
        Node(int key_,int val_){
            key=key_;
            val=val_;
            prev = nullptr;
            next = nullptr;
        }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>m;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node*newNode){
        Node*temp=head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=temp;
        temp->prev=newNode;
    }
    void deleteNode(Node*delNode){
        Node* delPrev=delNode->prev;
        Node* delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node*resNode=m[key];
            int res=resNode->val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* existingNode=m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        if(cap==m.size()){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        m[key]=head->next;
    }
};
int main(){
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1)<<endl; // returns 1
    obj->put(3,3);           // evicts key 2
    cout<<obj->get(2)<<endl; // returns -1 (not found)
    obj->put(4,4);           // evicts key 1
    cout<<obj->get(1)<<endl; // returns -1 (not found)
    cout<<obj->get(3)<<endl; // returns 3
    cout<<obj->get(4)<<endl; // returns 4
    return 0;
}