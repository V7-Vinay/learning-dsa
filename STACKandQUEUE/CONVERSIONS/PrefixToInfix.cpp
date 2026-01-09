#include <bits/stdc++.h>
using namespace std;
string prefixToPostfix(string prefix) {
    stack<string> st;
    int i=prefix.length()-1;
    for (int j=i; j>=0; j--) {
        char c = prefix[j];
        if (isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string expr = "(" + op1  + op2 + c+")";
            st.push(expr);
        }
    }
    return st.top();
}
int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;
    string infix = prefixToPostfix(prefix);
    cout << "Infix Expression: " << infix << endl;
    return 0;
}
