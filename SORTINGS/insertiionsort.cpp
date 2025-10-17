#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int n,int arr[]){
    for(int i =1;i<n;i++){
        int v=arr[i],j=i-1;
        while (j>=0&&arr[j]>v)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=v;
    }
    cout<<"the sored array using insertion sort is : \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
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
    insertion_sort(n,a);
    return 0;
}