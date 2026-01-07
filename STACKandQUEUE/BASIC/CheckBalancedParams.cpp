#include<bits/stdc++.h>
using namespace std;
bool areParametersBalanced( string &expr) {
    stack<char> s;
   

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {

            if(s.empty()) {
                return false;
            }
           if(s.top() == '}' && s.top() != '{'){
               return false;
           }
              if(s.top() == ')' && s.top() != '('){
                return false;
              }
                if(s.top() == ']' && s.top() != '['){
                    return false;
                }
            s.pop();
        }
        
    }
    return s.empty();
}
int main() {
    string expr = "{()}[]";

    if (areParametersBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}