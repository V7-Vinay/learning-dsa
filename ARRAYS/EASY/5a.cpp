// left rotste array by on pos
#include<bits/stdc++.h>
using namespace std;
void left(int ar[],int n){
    int f=ar[0];
    for(int i=1;i<n;i++){
        ar[i-1]=ar[i];
    }
    ar[n-1]=f;
}
int main(){
    int n;
    cout<<"enter the number of elemnets of the array:\n";
    cin>>n;
  int arr[n];
    cout<<"enter the "<<n<<" of elemnets of the array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    left(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

