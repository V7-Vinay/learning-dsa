// Problem Statement: You are given a string s and a positive integer k.
// Return the number of substrings that contain exactly k distinct characters.
// Example 1:  
// Input: s = "abcbaa", k = 3  
// Output: 5  
// Explanation:  All substrings with exactly 3 distinct characters:  
// "abc", "abcb", "abcba", "bcba", "cbaa"  
// Total = 5.
#include <bits/stdc++.h>
using namespace std;    
int atmostK(string s,int k){
    int left=0,right=0,res=0;
    unordered_map<char,int>freq;
    for(int right=0;right<s.size();right++){
        freq[s[right]]++;
        while(freq.size()>k){
            freq[s[left]]--;
            if(freq[s[left]]==0)freq.erase(s[left]);
            left++;
        }
        res+=right-left+1;
    }
    return res; 
}
int main()
{
    string s = "abcbaa";
    int k=3;
    int result = atmostK(s,k) - atmostK(s,k-1);
    cout << " Number of substrings with exactly k distinct characters is :"<<result;
    return 0;
}