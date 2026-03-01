#include<bits/stdc++.h>
using namespace std;
int subarraysWithKDistinctBrute(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>mp;
            for(int j=i;j<nums.size();j++){
                mp[nums[j]]++;
                if(mp.size()>k)break;
                else if(mp.size()==k)count++;
            }
        }
        return count;
    }

    int helper(vector<int>& nums, int k){
       int count=0;
       int l=0;
       int x=0;
       unordered_map<int,int>mp;
           for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            x=mp.size();
            while(x>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                    x--;
                }
                l++;
            }
            count=count+(r-l+1);
           }
           return count++;
        
        return count;
    }
    int subarraysWithKDistinctOptimal(vector<int>& nums, int k) {
     return  helper(nums,k)-helper(nums,k-1);
    }
    int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << subarraysWithKDistinctBrute(nums, k) << endl;
    cout << subarraysWithKDistinctOptimal(nums, k) << endl;    
    return 0;
}