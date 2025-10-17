//brute fforce method to move zwero to last
#include<bits/stdc++.h>
using namespace std;
void movezero(int arr[],int n){
int temp[n],j=0;
for(int i=0;i<n;i++){
    if(arr[i]>0){
        temp[j++]=arr[i];
    }
}
for(int i=0;i<j;i++){
    arr[i]=temp[i];                                                                                                                                                                                             
}
for(int i=j;i<n;i++){
    arr[i]=0;
}
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
    movezero(arr ,n);
    cout<<"after moving zero to end array  is:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        
    }
    return 0;
}