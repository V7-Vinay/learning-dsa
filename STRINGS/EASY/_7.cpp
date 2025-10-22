// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
//  typically using all the original letters exactly once.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// anagram of abc are "abc", "acb", "bac", "bca", "cab", "cba"
#include<bits/stdc++.h>
using namespace std;
bool isAnagramBruteForce(string &s,string &t){
    if(s.size()!=t.size())return false;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    // return s==t; or 
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]) return false;
    }
    return true;
}

bool isAnagramOptimal(string &s,string &t){
    if(s.size()!=t.size())return false;
    int check[26]={0};
     for (char &c : s) c = toupper(c);
    for (char &c : t) c = toupper(c);
    for(int i=0;i<s.size();i++){
        check[s[i]-'A']++;//in case all are lowercase use 'a' instead of 'A' and for uppercase use 'A'
        check[t[i]-'A']--;// remove above for loops if they are in lower case
    }
    for(int i=0;i<26;i++){
        if(check[i]!=0)return false;
    }
    return true;
}

int main(){
    string s="anagram";
    string t="nagaram";
    cout<<"checking using brute force approach: ";
    cout<<isAnagramBruteForce(s,t)<<endl;
    cout<<"checking using optimal approach: ";
    cout<<isAnagramOptimal(s,t);
    return 0;
}