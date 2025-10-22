// Problem Statement: Given an input string, containing upper-case and lower-case letters, digits, and spaces( ' ' ). A word is defined as a sequence of non-space characters. The words in s are separated by at least one space.

// Return a string with the words in reverse order, concatenated by a single space.
// Example 2:
// Input: s = " amazing coding skills "
// Output: "skills coding amazing"
// Explanation:
// // The input string has leading and trailing spaces, as well as multiple spaces between the words "amazing", "coding", and "skills".
//  After trimming the leading and trailing spaces and reducing the multiple spaces between words to a single space,
//   the words are "amazing", "coding", and "skills". Reversing the order of these words gives "skills", "coding", and "amazing".
//    The output string should not have any leading or trailing spaces and should have exactly one space between each word.
#include<bits/stdc++.h>
using namespace std;
string reverseWordsBrute(string s) {
    vector<string>words;
    string temp="";
    int n=s.size();
    int start=0;
    int end=0;
    int i=0;        
    while( i<n){
        while(i<n && s[i]==' '){
            i++;
        }
        if(i>=n) break; 
        start=i;
        while(i<n&&s[i]!=' '){
            i++;
        }
        end=i-1;
        words.push_back(s.substr(start,end-start+1));  
    }
    for(int i=words.size()-1;i>=0;i--){
           temp+=words[i];
           if(i!=0) temp+=' ';
        } 
    return temp;    
}


void rev(string &s ,int left , int right){
    while(left<right){
        swap(s[left++],s[right--]);
    }
}

string reverseOptimal(string s){
    int n=s.size();
    int i=0,start=0,end=0,j=0;
    rev(s,0,n-1);
    while(j<n){
        while(j<n&&s[j]==' ' )j++;
        if(j==n)break;
        start=i;
        while(j<n&&s[j]!=' '){
            s[i++]=s[j++];
        }
        end=i-1;
        rev(s,start,end);
        if(j<n){
            s[i++]=' ';
        }
       
        }
         while(i>0&&s[i-1]==' '){
            i--;
    }
    return s.substr(0,i);
}
int main(){
    string s = "  amazing   coding skills  ";
    cout << "Reversed Words: '" << reverseWordsBrute(s) << "'" << endl;
    cout << "Reversed Words Optimal: '" << reverseOptimal(s) << "'" << endl;
    return 0;
}