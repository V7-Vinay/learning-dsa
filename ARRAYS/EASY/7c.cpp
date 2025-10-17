//best approach for moving zero to last
#include<bits/stdc++.h>
using namespace std;
void movezero(int arr[],int n){
    int j =-1;
for(int i=0;i<n;i++){
    if(arr[i]==0){
        j = i;
        break;

    }
   
}
if(j==-1)return;
for(int i=j+1;i<n;i++){
    if(arr[i]!=0){
        swap(arr[i],arr[j]);
    j++;
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