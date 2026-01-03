#include<bits/stdc++.h>
using namespace std;
int _1ToN(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result ^= i;
    }
    return result;
}
int LtoR(int l ,int r) {
    int result = 0;
    for (int i = l; i <= r; i++) {
        result ^= i;
    }
    return result;
}
int optimal1toN(int n){
    if(n%4==0)return n;
    if(n%4==1)return 1;
    if(n%4==2)return n+1;
    return 0;
}
int optimalLtoR(int l ,int r){
    return optimal1toN(r)^optimal1toN(l-1);
}
int main() {
    int l = 3;
    int r = 9;
    cout << LtoR(l, r) << endl; // Output: 10
    cout << optimalLtoR(l, r) << endl; // Output: 10
    return 0;
}