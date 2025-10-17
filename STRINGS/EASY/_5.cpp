// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character
//  while preserving the order of characters. No two characters may map to the same character, 
//  but a character may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true

// Explanation:
// The strings s and t can be made identical by:
// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.

// Example 2:
// Input: s = "foo", t = "bar"
// Output: false

// Explanation:
// The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s,string t){
int m1[256]={0};
int m2[256]={0};
int n = s.length();
for(int i=0;i<n;i++){
    if(m1[s[i]]!=m2[t[i]])return false;
    m1[s[i]]=i+1;
    m2[t[i]]=i+1;
}
return true;
}
int main(){
    string s,t;
    cout<<"enter the first string:";
    cin>>s;
    cout<<"enter the second string:";
    cin>>t;
    if(isIsomorphic(s,t)){
        cout<<"the strings are isomorphic.";
    }else{
        cout<<"the strings are not isomorphic.";
    }
    return 0;
}   