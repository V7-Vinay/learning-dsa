/*Time Complexity: O(N), where N = size of array+1.
Reason: Here, we need only 1 loop to calculate the XOR. The loop runs for approx. N times. So, the time complexity is O(N).

Space Complexity: O(1) as we are not using any extra space.
Note: Among the optimal approaches, the XOR approach is slightly better than the
 summation one because the term (N * (N+1))/2 used in the summation 
 method cannot be stored in an integer if the value of N is big (like 105). In that case,
  we have to use some bigger data types. But we will face no issues like this while using the XOR approach.
*/
#include<bits/stdc++.h>
using namespace std;
int getmissing(int arr[],int n){
   int xor1=0,xor2=0;
    for(int i=1;i<=n;i++){
        xor1^=arr[i-1];
        xor2^=i;
   }
  return xor1^xor2;
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