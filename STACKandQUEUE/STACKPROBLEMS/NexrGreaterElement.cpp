#include<bits/stdc++.h>
using namespace std;
 vector<int> nextGreaterElementsCircularOptimal(vector<int>& nums) {
        stack<int>st;
        int n =nums.size();
        vector<int>nge(n);
        for(int i=2*n-1;i>=0;i--){//for circular we traverse 2 times  
            //  if only on the right side then we traverse only n times n-1 to 0
            while(!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty())nge[i]=st.top();
                else
                nge[i]=-1;
            }
            st.push(nums[i%n]);
        }
        return nge;
    }

    vector<int> nextGreaterElements(vector<int> arr) {
        int n = arr.size(); 
        vector<int> ans(n, -1);
        for(int i=0; i < n; i++) {
            int currEle = arr[i];
            for(int j=1; j < n; j++) {
                int ind = (j+i) % n;
                if(arr[ind] > currEle) {
                    ans[i] = arr[ind];
                    break;
                }    
            }
        }
        return ans;
    }


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>result=nextGreaterElements(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }   
    vector<int>resultOptimal=nextGreaterElementsCircularOptimal(nums);
    cout<<endl; 
    for(int i=0;i<resultOptimal.size();i++){
        cout<<resultOptimal[i]<<" ";
    }


    return 0;
}