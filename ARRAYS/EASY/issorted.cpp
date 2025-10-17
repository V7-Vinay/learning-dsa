#include<bits/stdc++.h>
using namespace std;
bool issorted(vector<int> arr ,int n){
    if(n<2)
    return true;
 for(int i =0;i<n-1;i++){
    if(arr[i]>arr[i+1])
    return false;
 }
 return true;
}
int main(){
    int n;
    cout<<"enter the number of elemnets of the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the "<<n<<" of elemnets of the array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  if(issorted(arr,n)){
    cout<<"sorted";
  }else{
    cout<<"unsorted";
  }

    return 0 ;

}