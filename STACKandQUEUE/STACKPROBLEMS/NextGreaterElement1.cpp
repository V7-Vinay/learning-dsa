#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementOptimal(vector<int>& nums1, vector<int>& nums2) {
       int n=nums2.size();
       stack<int>st;
        vector<int> mp(10001,-1);
       for(int i=n-1;i>=0;i--){
        while(!st.empty()&&st.top()<=nums2[i]){
            st.pop();
        }
        if(st.size()!=0)mp[nums2[i]]=st.top();
        st.push(nums2[i]);
       }
       int m=nums1.size();
       vector<int>ans(m);
       for(int i=0;i<nums1.size();i++){
        ans[i]=mp[nums1[i]];
       }
       return ans;
 }

 vector<int> nextGreaterElementBrute(vector<int>& nums1, vector<int>& nums2) {
       int n=nums2.size();
       stack<int>st;
        vector<int> mp(10001,-1);
       for(int i=n-1;i>=0;i--){
        while(!st.empty()&&st.top()<=nums2[i]){
            st.pop();
        }
        if(st.size()!=0)mp[nums2[i]]=st.top();
        st.push(nums2[i]);
       }
       int m=nums1.size();
       vector<int>ans(m);
       for(int i=0;i<nums1.size();i++){
        ans[i]=mp[nums1[i]];
       }
       return ans;
    }

    int main() {
        vector<int> nums1 = {4,1,2};
        vector<int> nums2 = {1,3,4,2};
        
        vector<int> resultOptimal = nextGreaterElementOptimal(nums1, nums2);
        cout << "Optimal Approach Result: ";
        for (int num : resultOptimal) {
            cout << num << " ";
        }
        cout << endl;

        vector<int> resultBrute = nextGreaterElementBrute(nums1, nums2);
        cout << "Brute Force Approach Result: ";
        for (int num : resultBrute) {
            cout << num << " ";
        }
        cout << endl;

        return 0;
    }