#include<bits/stdc++.h>
using namespace std;
string postfixToPrefix(string postfix) {
   stack<string>st;
   for(int i=0;i<postfix.size();i++){
    char c=postfix[i];
    if(isalnum(c)){
        st.push(string(1,c));
    }else{
        string first=st.top(); st.pop();
        string second=st.top(); st.pop(); 
        string expr=c+second+first;
        st.push(expr);
    }
   }
   return st.top();
}
int main(){
    string postfix;
    cout<<"Enter Postfix Expression: ";
    cin>>postfix;
    string prefix=postfixToPrefix(postfix);
    cout<<"Prefix Expression: "<<prefix<<endl;
    return 0;
}