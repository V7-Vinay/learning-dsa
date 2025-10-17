#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (i <= high - 1 && arr[i] <= pivot) { 
            i++;
        }

        while (j >= low + 1 && arr[j] > pivot) { 
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

void quickSort(vector<int> &arr) {  // ✅ Pass by reference to modify the original array
    qs(arr, 0, arr.size() - 1);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr;  // ✅ Initialize an empty vector
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);  // ✅ Dynamically push elements
    }

    cout << "Before Quick Sort:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    quickSort(arr);  // ✅ Sorting done in place

    cout << "After Quick Sort:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
