#include <bits/stdc++.h>
using namespace std;
 vector<int> replaceWithRankBrute(vector<int>& arr) {
    vector<int> rankArr(arr.size());
    for(int i=0;i<arr.size();i++){
        unordered_set<int>s;
        for(int j=0;j<arr.size();j++){
        if(arr[j]<=arr[i]) s.insert(arr[j]);
        }
        rankArr[i]=s.size();
    }
    return rankArr;
 }

 vector<int> replaceWithRankOptimal(vector<int>& arr) {
    vector<int> rankArr;
    vector<int>copy=arr;
    sort(copy.begin(),copy.end());
    int rank=1;
    unordered_map<int,int>mp;
    for(auto num:copy){
        if(mp.find(num)==mp.end()){
            mp[num]=rank;
            rank++;
        }
    }
    for(auto num:arr){
        rankArr.push_back(mp[num]);
    }
    return rankArr;
 }
 int main(){
    vector<int> arr={40,10,20,30};
    vector<int> rankArr=replaceWithRankOptimal(arr);
    for(auto rank:rankArr){
        cout<<rank<<" ";
    }
    return 0;
}