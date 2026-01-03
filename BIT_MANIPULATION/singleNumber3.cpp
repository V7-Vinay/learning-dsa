#include<bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int>& nums) {
    unordered_map<int,int>mp;
    for(int num:nums){
        mp[num]++;
    }
    vector<int>result;
    for(auto it:mp){
        if(it.second==1){
            result.push_back(it.first);
        }
    }
    sort(result.begin(),result.end());
    return result;
}

vector<int> singleNumberOptimal(vector<int>& nums) {
   int Xor=0;
   for(int num:nums){
    Xor^=num;
   }
   int rightBit=(Xor&(Xor-1))^Xor;
   int xor1=0,xor2=0;
   for(int num:nums){
    if(rightBit&num){
        xor1^=num;
    }
    else{
        xor2^=num;
    }
   }
    if(xor1<xor2){
     return {xor1,xor2};
    }else{
        return {xor2,xor1};
    }
}
int main() {
    vector<int> nums = {1,4,4,2,1,3,2,5};
    vector<int> result = singleNumber(nums);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl; // Output: [3, 5]
    vector<int> optimalResult = singleNumberOptimal(nums);
    cout << "[" << optimalResult[0] << ", " << optimalResult[1] << "]" << endl; // Output: [3, 5]
    return 0;
}