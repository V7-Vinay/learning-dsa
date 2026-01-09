#include <bits/stdc++.h>
using namespace std;
string postfixToInfix(string postfix) {
    stack<string> st;
    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }
    return st.top();
}
int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;
    string infix = postfixToInfix(postfix);
    cout << "Infix Expression: " << infix << endl;
    return 0;
}
