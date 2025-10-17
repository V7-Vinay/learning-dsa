// QUESTION NUMBERED 2

// Reverse Words in a String

// Given an input string s, reverse the order of the words.

// Input: s=”this is an amazing program”
// Output: “program amazing an is this”

#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
  s+=" ";
  stack<string> st;
  string word="";
  for(int i=0;i<s.length();i++){
    if(s[i]==' '){
      if(word.length()>0){ // or if(word=="")
        st.push(word);
        word="";
      }
    }else{
      word+=s[i];
    }
  }
  string result="";
  while(!st.empty()){
    result+=st.top();
    st.pop();
    if(!st.empty()) result+=" ";
  }

    return result;
}

string reverseWordsOptimized(string s) {
int left=0,right=s.length()-1;
while(left<=right&&s[left]==' ')left++;// trims the leading spaces 
while(right>=left&&s[left]==' ')right--;// trims the trailing spaces

string temp="";
string result="";
while(left<=right){
  if (s[left]!=' '){
    temp+=s[left];
  }else if(s[left]== ' '){
    if(temp!=""){  //removes the extra spaces in the middle 
      if(result!="")result=temp+" "+result;
    else result=temp;
    temp="";
    }
  }
  left++;
}
if(temp!=""){
  if(result!="") result=temp+" "+result;
  else result=temp; 
}
return result;
}
int main(){
    string s = "this is an amazing program";
    cout <<"brute force:"<< reverseWords(s) << endl; // Output: "program amazing an is this"
    cout << "optimal:"<<reverseWordsOptimized(s) << endl; // Output: "program amazing an is this"
    return 0;       
}