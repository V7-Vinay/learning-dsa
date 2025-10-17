// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs){
    if(strs.empty())return "";
    sort(strs.begin(),strs.end());  
    string first = strs[0];
    string last = strs[strs.size()-1];
    string prefix="";
    int minLegnth = min(first.size(),last.size());
    for(int i=0;i<minLegnth;i++){
        if(first[i]==last[i]){
            prefix+=first[i];
        }else{
            break;
        }
    }
    return prefix;  
}
int main(){
    int n;
    cout<<"enter the number of strings:";
    cin>>n;
    vector<string> strs(n);
    cout<<"enter the strings:"<<endl;
    for(int i=0;i<n;i++){
        cin>>strs[i];
    }
    string result = longestCommonPrefix(strs);
    if(result==""){
        cout<<"there is no common prefix among the input strings.";
    }else{
        cout<<"the longest common prefix is:"<<result;
    }
    return 0;
}