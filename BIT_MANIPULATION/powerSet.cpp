#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>powerSet(vector<int>&nums){
    int n=nums.size();
    int subsets=1<<n;
    vector<vector<int>>result;
    for(int num=0;num<subsets;num++){
        vector<int>subset;
        for(int i=0;i<n;i++){
            if(num&1<<i){
                subset.push_back(nums[i]);
            }
        }
        result.push_back(subset);
    }
    return result;
}
int main() {
    vector<int>nums={1,2,3};
    vector<vector<int>>result=powerSet(nums);
    for(auto subset:result){
        cout<<"[ ";
        for(int num:subset){
            cout<<num<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
