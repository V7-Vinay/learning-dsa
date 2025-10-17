//my soln to move 0 to last
#include<bits/stdc++.h>
using namespace std;
void movezero(int arr[],int n){
    int i=0,j=n-1;
    while(i<=j){
        if(arr[i]>0){
            i++;
        }else{
            if(arr[j]>0){
                swap(arr[i],arr[j]);
            }else{
                j--;
            }
        }
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