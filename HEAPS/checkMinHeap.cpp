#include <bits/stdc++.h>
using namespace std;
bool isMinHeap(int arr[],int n){
    for(int i=0;i<=n/2;i++){
        if(2*i+1<n&&arr[i]>arr[2*i+1]){
            return false;
        }
        if(2*i+2<n&&arr[i]>arr[2*i+2]){
            return false;
        }
    }
    return true;
}
int main(){
    int arr[]={1,3,5,7,9,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    if(isMinHeap(arr,n)){
        cout<<"Yes it is a min heap"<<endl;
    }
    else{
        cout<<"No it is not a min heap"<<endl;
    }
    return 0;
}