 #include <bits/stdc++.h>
using namespace std;
 vector<int> nextSmalllestElement(vector<int>& nums) {
        stack<int>st;
        int n =nums.size();
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() >= nums[i]){
                st.pop();
            }//for circular array use simple modulo operation as said in next greater element circular  
                if(!st.empty())nge[i]=st.top();
                else
                nge[i]=-1;
            
            st.push(nums[i]);
        }
        return nge;
    }
int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = nextSmalllestElement(nums);
    for (int val : result) {
        cout << val << " ";
    }   
    return 0;
}