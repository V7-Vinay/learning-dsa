#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
    unordered_map<int,int>mp;
    for(int num:nums){
        mp[num]++;
    }
    for(auto it:mp){
        if(it.second==1){
            return it.first;
        }
    }
    return -1;
}
int singleNumber32bit(vector<int>& nums) {
    int result=0;
    for(int i=0;i<32;i++){
        int sum=0;
        for(int num:nums){
            if(num&(1<<i)){
                sum++;
            }
        }
        if(sum%3!=0){
            result|=(1<<i);
        }
    }
    return result;
}   
int singlesort(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i+=3){
       if(nums[i]!=nums[i-1]){
        return nums[i-1];
       }
    }
    return nums[nums.size()-1];
}   
int singleNumberOptimal(vector<int>& nums) {
    int ones=0,twos=0;
    for(int num:nums){
        ones=(ones^num)&(~twos);
        twos=(twos^num)&(~ones);
    }
    return ones;
}   
int main() {
    vector<int> nums = {4,1,1, 2, 2, 1, 2};
    cout << singleNumber(nums) << endl; // Output: 4
    cout << singleNumber32bit(nums) << endl; // Output: 4
    cout << singlesort(nums) << endl; // Output: 4
    cout << singleNumberOptimal(nums) << endl; // Output: 4
    return 0;
}