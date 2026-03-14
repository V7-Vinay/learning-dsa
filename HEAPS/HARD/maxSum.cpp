#include <bits/stdc++.h>
using namespace std; 
vector<int>maxSumBrute(int k,vector<int>&nums1,vector<int>&nums2){
    vector<int>allSums;
    for(int i:nums1){
        for(int j:nums2){
            allSums.push_back(i+j);
        }
    }
    sort(allSums.begin(),allSums.end(),greater<int>());
         vector<int> result(allSums.begin(), allSums.begin() + k);
         return result;
    
    }

    vector<int>maxSumOptimal(int k,vector<int>&nums1,vector<int>&nums2){
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>visited;
        pq.push({nums1[0]+nums2[0], {0,0}});
        visited.insert({0,0});
        vector<int>result;
        while(k--){
            auto current = pq.top();
            pq.pop();
            result.push_back(current.first);
            int  i = current.second.first;
            int j = current.second.second; 
            if(i+1<nums1.size()&&!visited.count({i+1,j})){
                pq.push({nums1[i+1]+nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            } 
            if(j+1<nums2.size()&&!visited.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            } 
        }
        return result;
    }
    int main() {
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> result1 = maxSumBrute(k,nums1, nums2);
    vector<int> result2 = maxSumOptimal(k,nums1, nums2);

    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}