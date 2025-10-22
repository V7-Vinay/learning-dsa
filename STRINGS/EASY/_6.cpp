// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.
 
// Example 1:
// Input: s = "abcde", goal = "cdeab"
// Output: true

#include<bits/stdc++.h>
using namespace std;    

bool isRotatableBruteForce(string& s, string & goal){
    if(s.size()!=goal.size()) return false;
    string rotated="";
    for(int i=0;i<s.size();i++){
        rotated = s.substr(i) + s.substr(0,i);
        if(rotated==goal) return true;
    }
    return false;
}

bool isRotatableOptimal(string& s, string & goal){
        if(s.size()!=goal.size()) return false;
        string doubledS = s + s ;
        return(doubledS.find(goal) != string::npos);
}

int main(){
    string s="abcde";
    string goal="cdeab";
    cout<<"checking using brute force approach: ";
    cout<<isRotatableBruteForce(s,goal)<<endl;
    cout<<"checking using optimal approach: ";
    cout<<isRotatableOptimal(s,goal);
    return 0;
}