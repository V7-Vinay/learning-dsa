// LARGEST ODD NUMBER IN THE STRING

// EXAMPLE 1:
// Input: num = "52"
// OUTPUT: "5"
// EXPLANATION: The largest odd number that can be formed is "5".

// EXAMPLE 2:
// Input: num = "04205" 
// Output: "5"
// EXPLANATION: there is only a single odd number in the given string.
#include<bits/stdc++.h>
using namespace std;
string LargestOdddNumber(string& num){
    int ind =-1;
    for(int i=num.length()-1;i>=0;i--){
        if((num[i]-'0')%2!=0){
            ind = i;
            break;
        }
    }
    int i=0;
    while(i<=ind && num[i]=='0'){
        i++;
    }
    return num.substr(i,ind-i+1);
}
int main(){
    string num;
    cout<<"enter the number string:";
    cin>>num;
    cout<<"the largest odd number is:";
    cout<<LargestOdddNumber(num);
    return 0;
}