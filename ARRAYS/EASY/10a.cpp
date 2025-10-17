/*Time Complexity: O(N) + O(N) ~ O(2*N),  where N = size of the array+1.
Reason: For storing the frequencies in the hash array, the program takes O(N) time complexity and for checking the frequencies in the second step again O(N) is required. So, the total time complexity is O(N) + O(N).

Space Complexity: O(N), where N = size of the array+1. Here we are using an extra hash array of size N+1.
*/
#include<bits/stdc++.h>
using namespace std;
int getmissing(int arr[],int n){
    int hash[n+1]={0};
    for(int i=0;i<n-1;i++){
        hash[arr[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==0)
        return i;
    }
    return -1;
}
int main(){
    int n;
    cout<<"enter the number of elements:\n";
    cin>>n;
    int arr[n];    cout<<"enter thr "<<n <<" elements of the aray";
    for(int i=0;i<n-1;i++)
    cin>>arr[i];
    int k=getmissing(arr,n);
    cout<<"the missing number is "<<k;
  return 0;
}