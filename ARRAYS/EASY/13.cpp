/*Time Complexity: O(N2) approx., where N = size of the array.
Reason: We are using two nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space.

*/
#include<bits/stdc++.h>
using namespace std;
int sublen(vector <int >arr,int k){
    int len=0;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            if(sum==k)
             len =max(len,j-i+1);
        }
    }
    return len;
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

    cout << "Enter the key sum to search:\n";
    cin >> key;
    int k=sublen(arr,key);
    cout<<"the length of the maax sub array gives "<<key<<"  sum is :\n"<<k;
    return 0;
}