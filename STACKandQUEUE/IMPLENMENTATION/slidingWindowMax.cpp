#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size()-k+1;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            int max=nums[i];
            for(int j=i;j<i+k;j++){
                if(nums[j]>max)max=nums[j];
            }
            arr[i]=max;
        }
        return arr;
    }
     vector<int> maxSlidingWindowDeque(vector<int>& nums, int k) {
        vector<int>arr;
        deque<int>dq;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty()&&dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty()&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                arr.push_back(nums[dq.front()]);
            }
        }
        return arr;
    }
int main(){
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int>result=maxSlidingWindowDeque(nums,k);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
     vector<int>result2=maxSlidingWindowDeque(nums,k);

    for(int i=0;i<result2.size();i++){
        cout<<result2[i]<<" ";
    }

    return 0;
}