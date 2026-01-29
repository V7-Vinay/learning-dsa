#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty()&&st.top().second<=price){
            span+=st.top().first;
            st.pop();
        }
        st.push({span,price});
        return span;

    }
};
int main(){
    StockSpanner* obj = new StockSpanner();
    vector<int>prices={100,80,60,70,60,75,85};
    for(int price:prices){
        int param_1 = obj->next(price);
        cout<<param_1<<" ";
    }
    cout<<endl;
    return 0;
}