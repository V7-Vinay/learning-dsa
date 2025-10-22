// Problem Statement: Given a string s, return the longest palindromic substring in s.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: It is the longest palindromic substring. "aba" is also a valid answer.
#include <bits/stdc++.h>
using namespace std;
int helper(string s,int left, int right){
    while(left>=0&&right<s.size()&&s[left]==s[right]){
        left--;
        right++;
    }
    return right-left-1;
}
string longestPalindrome(string s){
    int start=0,end=0;
    for(int i=0;i<s.size();i++){
        int oddlen=helper(s,i,i);
        int evenlen=helper(s,i,i+1);
        int maxlen = max(oddlen,evenlen);
        if(maxlen > end-start+1){
            start=i-(maxlen-1)/2;
            end=i+ maxlen/2;
        }
    }
    return s.substr(start,end-start+1);
}
int main()
{
    string s = "babad";
    cout << " Longest Palindromic Substring is :"<<longestPalindrome(s);
    return 0;
}