#include<bits/stdc++.h>
using namespace std;

class MinStack1 {
    stack<pair<int,int>>st;
public:
    MinStack1() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
            return ;
        }
        int mini=min(getMin(),val);
        st.push({val,mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
     return st.top().first;   
    }
    
    int getMin() {
     return st.top().second;          
    }
};

class MinStack2 {
    stack<long long>st;
    long long mini;
public:
    MinStack2() {
        
    }
    
    void push(int val) {
      if(st.empty()){
        st.push(val);
        mini=val;
      }
      else if(val>=mini){
        st.push(val);
      }else{
        st.push(2LL*val-mini);
        mini=val;
      }
    }
    
    void pop() {
        if(st.empty())return;
        long long x=st.top();
        if(x<mini){
            mini=2*mini-x;
        }
        st.pop();
    }
    
    int top() {
        if(st.empty())return -1;
        long long x=st.top();
        if(x<mini){
            return (int)mini;
        }
        return (int)x;

    }
    
    int getMin() {
     return (int)mini;
    }
};
int main() {
    MinStack1 minStack1;
    minStack1.push(-2);
    minStack1.push(0);
    minStack1.push(-3);
    cout<<minStack1.getMin()<<endl; // return -3
    minStack1.pop();
    cout<<minStack1.top()<<endl;    // return 0
    cout<<minStack1.getMin()<<endl; // return -2

    MinStack2 minStack2;
    minStack2.push(-2);
    minStack2.push(0);
    minStack2.push(-3);
    cout<<minStack2.getMin()<<endl; // return -3
    minStack2.pop();
    cout<<minStack2.top()<<endl;    // return 0
    cout<<minStack2.getMin()<<endl; // return -2

    return 0;
}