#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int n ,int arr[]){
    if(n==1)return;
    int didswap=0;
        for(int j=0;j<n-1;j++){

            if(arr[j+1]<arr[j]){
                int temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                didswap++;
            }
    }
    if(!didswap)return;
    bubble_sort(n-1,arr);

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
    
    cout<<"after sorting using bubble sort :\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}