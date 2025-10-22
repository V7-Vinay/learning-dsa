// Problem Statement: Given a valid parentheses string s, return the nesting depth of s. 
// The nesting depth is the maximum number of nested parentheses.
                
// Example 1:
// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3
// Explanation: Digit 8 is inside of 3 nested parentheses in the string.
#include<bits/stdc++.h>
using namespace std;
int maximumDepth(string &s){
    int curr=0,maxi=0;
    for(char c:s){
        if(c=='('){
            curr++;
            maxi=max(maxi,curr);
        }
        else if(c==')'){
            curr--;
        }
    }
    return maxi;
}
int main(){
    string s="(1+(2*3)+((8+(2)*7)/4))+1";
    cout<<maximumDepth(s);
    return 0;
}