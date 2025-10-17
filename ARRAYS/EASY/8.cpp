#include<bits/stdc++.h>
using namespace std;

int linearsearch(vector<int> arr, int key) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Enter the number of elements in the array:\n";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the " << n << " elements of the array:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key element to search:\n";
    cin >> key;

    int pos = linearsearch(arr, key);
    if (pos != -1)
        cout << "The key is found at position (0-based index): " << pos << endl;
    else
        cout << "Key not found in the array." << endl;

    return 0;
}
