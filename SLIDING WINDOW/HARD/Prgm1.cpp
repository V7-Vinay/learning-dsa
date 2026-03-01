#include<bits/stdc++.h>
using namespace std;
int subStringWithAtMostKDistinctBrute(string s ,int k){
    int length = 0;
    for(int i=0;i<s.length();i++){
        unordered_map<char,int> mp;
        for(int j=i;j<s.length();j++){
            mp[s[j]]++;
            if(mp.size()>k)break;
            length = max(length,j-i+1);
        }
    }
    return length;  
}
int subStringWithAtMostKDistinctOptimal(string s ,int k){
    if(k==0||s.length()==0)return 0;
    int length = 0;
    int l=0;
    unordered_map<char,int> mp;
    for(int r=0;r<s.length();r++){
        
       
       mp[s[r]]++;
       if(mp.size()>k){
        mp[s[l]]--;
        if(mp[s[l]]==0)mp.erase(s[l]);
        l++;
       }
       length=max(length,r-l+1);
    }
    return length;  
}
int main() {
    string s = "eceba";
    int k = 2;
        cout << subStringWithAtMostKDistinctBrute(s, k) << endl;
    cout << subStringWithAtMostKDistinctOptimal(s, k) << endl;
    return 0;
}