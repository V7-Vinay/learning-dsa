#include<bits/stdc++.h>
using namespace std;
int getdp( vector<int> &rr,int n){
    int i=0; 
    sort(rr.begin(),rr.end());
    for(int j=0;j<n-1;j++){
        if(rr[i]!=rr[j]){
          
          i++;
            rr[i]=rr[j];
        }
    }
    return i+1;
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
   cout<<"removing the duplicate elements of the array\n";
   int k=getdp(arr,n);
   cout<<"\nthe length of the array is:"<<  k;
   cout<<"\nthe elements are:\n";
   for(int i=0;i<k;i++){
    cout<<arr[i]<<" ";
   }
return 0;

}