// Problem Statement: You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.
// If two or more characters have same frequency then arrange them in alphabetic order.
// Examples
                
// Example 1:
// Input: s = "tree"
// Output: ['e', 'r', 't']
// Explanation:
// e → 2
// r → 1
// t → 1
// Since 'r' and 't' have the same frequency, they are sorted alphabetically → 'r' comes before 't'.
#include<bits/stdc++.h>
using namespace std;
class _1
{
private: 
static bool comparotor(pair<int,char>p1,pair<int,char>p2){
    if(p1.first>p2.first)return true;
    if(p1.first<p2.first)return false;
    return p1.second<p2.second;
}
   
public:
   vector<char> frequencySort(string &s){
    pair<int,char>freq[26];
    for(int i=0;i<26;i++){
        freq[i].first=0;
        freq[i].second='a'+i;
    }
    for(char c:s){
        freq[c-'a'].first++;
    }
    sort(freq,freq+26,comparotor);
    vector<char>ans;
    for(int i=0;i<26;i++){
        if(freq[i].first>0)
        ans.push_back(freq[i].second);
    }
    return ans;
   }
};
int main(){
    _1 obj;
    string s="tree";
    vector<char>res=obj.frequencySort(s);
    for(char c:res){
        cout<<c<<" ";
    }
    return 0;
}

