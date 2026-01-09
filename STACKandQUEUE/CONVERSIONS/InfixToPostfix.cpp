#include<bits/stdc++.h>
using namespace std;
int precedence(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1;
}
string infixToPostfix(string infix){
   int n=infix.length(),i=0;
   stack<char>st;
   string postfix="";
   while(i<n){
    char c=infix[i];
    if(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'){
        postfix+=c;
   }else if(c=='('){
    st.push(c);
   }else if(c==')'){
    while(!st.empty()&&st.top()!='('){
       postfix+= st.top();
       st.pop();
    }
    st.pop();
   }else{
    while(!st.empty()&&precedence(st.top())>=precedence(c)){
        postfix+=st.top();
        st.pop();
    }
    st.push(c);
   }
   i++;
   }
   while(!st.empty()){
    postfix+=st.top();
    st.pop();
   }
   return postfix;  
}
int main(){
    string infix;
    cout<<"Enter Infix Expression: ";
    cin>>infix;
    string postfix=infixToPostfix(infix);
    cout<<"Postfix Expression: "<<postfix<<endl;
    return 0;
}