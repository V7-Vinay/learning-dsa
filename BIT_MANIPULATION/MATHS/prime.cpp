#include <bits/stdc++.h>
using namespace std;
bool isPrimeBrute(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
bool isPrimeOptimal(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    bool primeBrute = isPrimeBrute(n);
    cout << "Brute Force: " << (primeBrute ? "Prime" : "Not Prime") << endl;
    bool primeOptimal = isPrimeOptimal(n);
    cout << "Optimal: " << (primeOptimal ? "Prime" : "Not Prime") << endl;
    return 0;
}
