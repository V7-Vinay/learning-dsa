#include<bits/stdc++.h>
using namespace std;
void rev(int arr[],int k ,int n){
    while(k<=n){
        int temp=arr[k];
        arr[k]=arr[n];
        arr[n]=temp;
        k++;n--;
    }
}
    void toleftrotate(int arr[],int k ,int n){
        rev(arr,0,k-1);
        rev(arr,k,n-1);
        rev(arr,0,n-1);
    }

    void torightrotate(int arr[],int k ,int n){
        rev(arr,n-k,n-1);
        rev(arr,0,n-k-1);
        rev(arr,0,n-1);
    }
    
    int main(){
        int k,n;
    cout<<"enter the number of elemnets of the array:\n";
    cin>>n;
  int arr[n];
    cout<<"enter the "<<n<<" of elemnets of the array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter the k value to rotate: \n";
    cin>>k;
    toleftrotate(arr,k,n);
    cout<<"after rotating the array by "<<k <<" position to left the array is:\n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    torightrotate(arr,k,n);
    torightrotate(arr,k,n);
    cout<<"after rotating the array by "<<k<<" position to right the  array is:\n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
    }
