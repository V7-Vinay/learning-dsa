#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
        stack<char> st;
        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        while (!res.empty() && res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
int main(){
    string num="1432219";
    int k=3;
    cout<<removeKdigits(num,k)<<endl;
    return 0;
}