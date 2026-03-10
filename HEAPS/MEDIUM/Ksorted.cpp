#include <bits/stdc++.h>
using namespace std;
vector<int> kthsortedBrute(vector<int>& nums, int k) {
     sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }

vector<int> kthsortedOptimal(vector<int>& nums, int k) {
      priority_queue <int, vector<int>, greater<int>> pq;
      vector<int> ans;
              for(int i=0;i<=k;i++) pq.push(nums[i]);
              
        for(int i=k+1;i<nums.size();i++){
           
                ans.push_back(pq.top());
                pq.pop();
                pq.push(nums[i]);
        } 
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans; 
    }
int main() {
    vector<int> nums = {3, 1, 5, 12,2, 11, 4};
    int k = 3;  
    vector<int> resultBrute = kthsortedBrute(nums, k);
    vector<int> resultOptimal = kthsortedOptimal(nums, k);
    cout << "Kth sorted elements (Brute Force): ";
    for(int num : resultBrute) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Kth sorted elements (Optimal): ";

    for(int num : resultOptimal) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}