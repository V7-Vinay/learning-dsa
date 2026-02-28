#include<bits/stdc++.h>
using namespace std;
int numSubarraysWithSumBrute(vector<int>& nums, int goal) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==goal)cnt++;
                else if(sum>goal)break;;
            }
        }
        return cnt;
    }

    int countSubarray(vector<int>& nums, int k){
        if(k<0)return 0;
        int l=0,r=0,cnt=0,sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    } 
    int numSubarraysWithSumOptimal(vector<int>& nums, int goal) {
       return(countSubarray(nums,goal)-countSubarray(nums,goal-1));
    }
    int main(){
     vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << numSubarraysWithSumBrute(nums, goal) << endl; 
    cout << numSubarraysWithSumOptimal(nums, goal) << endl; 
    return 0;
        
    }