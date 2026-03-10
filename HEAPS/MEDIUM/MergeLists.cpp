#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeListBrute(vector<ListNode*> lists){
    vector<int> v;
    for(auto list:lists){
        while(list){
            v.push_back(list->val);
            list = list->next;
        }
    }
    sort(v.begin(), v.end());
    ListNode* head = new ListNode(0);
    ListNode* temp = head;  
    for(int i=0; i<v.size(); i++){
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }
    return head->next;
}

class Compare{
    public:
    bool operator()(ListNode*a,ListNode*b){return a->val>b->val;}
 };

    
    ListNode* mergeKListsOptimal(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;
        for(auto list:lists){
            if(list!=NULL){
                pq.push(list);
            }
        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(!pq.empty()){
            ListNode*smallest=pq.top();
            pq.pop();
            temp->next=smallest;
            temp=temp->next;
            if(smallest->next!=NULL)pq.push(smallest->next);
        }
        return dummy->next;
    }

int main(){
    ListNode* head1=new ListNode(1);
    head1->next=new ListNode(4);
    head1->next->next=new ListNode(5);
    ListNode* head2=new ListNode(1);
    head2->next=new ListNode(3);
    head2->next->next=new ListNode(4);
    ListNode* head3=new ListNode(2);
    head3->next=new ListNode(6);
    vector<ListNode*> lists={head1,head2,head3};
     // ListNode* mergedList=mergeKListsOptimal(lists);
     // while(mergedList){
     //     cout<<mergedList->val<<" ";
     //     mergedList=mergedList->next;
     // }
    // cout<<endl;
     ListNode* mergedList1=mergeListBrute(lists);
    while(mergedList1){
        cout<<mergedList1->val<<" ";
        mergedList1=mergedList1->next;
    }
    cout<<endl;
    return 0;

}