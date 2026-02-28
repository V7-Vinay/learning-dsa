#include<bits/stdc++.h>
using namespace std;
int numberOfSubarraysBrute(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2!=0){
                    cnt++;
                }
                if(cnt>k)break;
                if(cnt==k)ans++;
            }
            
        }
        return ans;
    }

    int numberOfSubarraysBetter(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>freq;
        freq[0]=1;
       int  cnt=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]%2==1)cnt++;
           if(freq.count(cnt-k))
           ans+=freq[cnt-k];
        freq[cnt]++;
        }
        return ans;
    }
int  nicesb(vector<int>& nums, int k){
        int l=0,r=0,cnt=0,ans=0;
        while(r<nums.size()){
            if(nums[r]%2!=0)cnt++;
            
            while(cnt>k){
                if(nums[l]%2!=0)cnt--;
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
     }
    int numberOfSubarraysOptimal(vector<int>& nums, int k) {
       return nicesb(nums,k)-nicesb(nums,k-1);
    }

    int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << numberOfSubarraysBetter(nums, k) << endl;
     cout << numberOfSubarraysBrute(nums, k) << endl;
      cout << numberOfSubarraysOptimal(nums, k) << endl;

    return 0;
}