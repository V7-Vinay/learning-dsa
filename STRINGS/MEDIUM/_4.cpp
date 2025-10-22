// Problem Statement: Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
// The algorithm for myAtoi(string s) is as follows:
// 1. Whitespace: Ignore any leading whitespace (" ").
// 2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// 3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// 4. Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.

// Example 1:
// Input: s = "1337c0d3"
// Output: 1337
// Explanation:
// Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
// Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
// Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s){
        int res=0,sign=1,i=0;
        while(i<s.size()&&s[i]==' ')i++;
        if(i==s.size())return 0;
        if(s[i]=='-'){
        sign=-1;
        i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(i<s.size()&& isdigit(s[i])){
            res = res*10 + (s[i]-'0');
            if(res*sign>INT_MAX) return INT_MAX;
            if(res*sign<INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(res*sign);
}
int main()
{
    string s = "   -0042vyh7";
    cout << " my atoi of s is :"<<myAtoi(s);
    return 0;
}