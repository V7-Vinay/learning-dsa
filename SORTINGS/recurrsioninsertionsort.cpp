#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int n,int i,int arr[]){
   
    if(i==n)return;
        int v=arr[i],j=i-1;
        while (j>=0&&arr[j]>v)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=v;
    
    
    insertion_sort(n,i+1,arr);
    
   
}
int main(){
    int n;
    cout<<"enter the number of elemnets in the array\n";
    cin>>n;
    int a[n];
    cout<<"enter  elemnets of the array \n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    insertion_sort(n,1,a);
    cout<<"the sored array using insertion sort is : \n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}