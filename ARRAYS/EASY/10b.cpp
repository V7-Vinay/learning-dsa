/*ime Complexity: O(N), where N = size of array+1.
Reason: Here, we need only 1 loop to get the sum of the array elements. The loop runs for approx. N times. So, the time complexity is O(N).

Space Complexity: O(1) as we are not using any extra space*/
#include<bits/stdc++.h>
using namespace std;
int getmissing(int arr[],int n){
    int nsum=(n*(n+1))/2;
    int sum=0;
    for(int i=0;i<n-1;i++){
        sum+=arr[i];
    }
    return nsum-sum;
}
int main(){
    int n;
    cout<<"enter the number of elements:\n";
    cin>>n;
    int arr[n];    cout<<"enter thr "<<n-1 <<" elements of the aray";
    for(int i=0;i<n-1;i++)
    cin>>arr[i];
    int k=getmissing(arr,n);
    cout<<"the missing number is "<<k;
  return 0;
}