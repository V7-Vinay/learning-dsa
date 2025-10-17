#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int n ,int arr[]){
    for(int i=1;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j+1]<arr[j]){
                int temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"after sorting using bubble sort :\n";
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
    bubble_sort(n,a);
    return 0;
}