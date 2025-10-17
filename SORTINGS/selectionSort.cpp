#include<bits/stdc++.h>
using namespace std;
void selection_sort(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j =i+1;j<n;j++){
            if(arr[j]<arr[mini])
            mini=j;
        }
        swap(arr[i],arr[mini]);
    }
    cout<<"the sorted array is "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"enter the number of elements in array "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the "<< n << " elements of array "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   
    cout<<"enter sorted array is ";
    selection_sort(n,arr);
    return 0;

}