#include<bits/stdc++.h>
using namespace std;
vector<int> primesInRange(vector<vector<int>>& queries) {
    // Step 0: Handle empty input
    if (queries.empty()) return {};

    // Step 1: Find maximum value needed
    int maxVal = 0;
    for (auto &q : queries) {
        maxVal = max(maxVal, q[1]);
    }

    // Step 2: Sieve of Eratosthenes
    vector<bool> isPrime(maxVal + 1, true);
    if (maxVal >= 0) isPrime[0] = false;
    if (maxVal >= 1) isPrime[1] = false;

    for (int i = 2; i * i <= maxVal; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxVal; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Step 3: Prefix sum of primes
    vector<int> prefix(maxVal + 1, 0);
    for (int i = 1; i <= maxVal; i++) {
        prefix[i] = prefix[i - 1] + (isPrime[i] ? 1 : 0);
    }

    // Step 4: Answer queries
    vector<int> ans;
    for (auto &q : queries) {
        int l = q[0], r = q[1];
        if (l == 0)
            ans.push_back(prefix[r]);
        else
            ans.push_back(prefix[r] - prefix[l - 1]);
    }

    return ans;
}

int main() {
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> results = primesInRange(queries);
    for (int res : results) {
        cout <<"row :" <<res << endl;
    }

    return 0;
}