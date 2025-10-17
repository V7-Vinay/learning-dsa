#include<bits/stdc++.h>
using namespace std;
int getduplicate(vector<int> &arr,int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int k =s.size();
 int j=0;
 for(int x :s){
    arr[j++]=x;
 }
 return k;
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
   int k=getduplicate(arr,n);
   cout<<"\nthe length of the array is:"<<  k;
   cout<<"\nthe elements are:\n";
   for(int i=0;i<k;i++){
    cout<<arr[i]<<" ";
   }
return 0;

}
