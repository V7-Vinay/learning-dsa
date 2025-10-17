// QUESTION NUMBERED 1

// Remove Outermost Parentheses
// Given a valid parentheses string s, your task is to remove the outermost 
// parentheses from every primitive component of s and return the resulting string.

// A valid parentheses string is either empty (""), "(" + A + ")", or A + B, 
// where A and B are valid parentheses strings, and + represents string concatenation. 
// A primitive valid parentheses string is a non-empty valid parentheses string that 
// cannot be split into two non-empty valid parentheses strings.

#include<bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s) {
    string result;
    int open = 0;
    for (char c : s) {
        if (c == '(') {
            if (open > 0) {
                result += c;
            }
            open++;
        } else {
            open--;
            if (open > 0) {
                result += c;
            }
        }
    }
    return result;
}
int main(){
    string s = "(()())(())";
    cout << removeOuterParentheses(s) << endl; // Output: "()()()"
    return 0;
}