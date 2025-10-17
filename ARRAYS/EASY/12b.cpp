/*Time Complexity: O(N)+O(N)+O(N), where N = size of the array
Reason: One O(N) is for finding the maximum, the second one is to hash the elements and the third one is to search the single element in the array.

Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.*/
//better solution for 12.cpp
#include<bits/stdc++.h>
using namespace std;
int getsingle(vector <int >arr){
   int maxi=0,n=arr.size();
   for(int i=0;i<n;i++)
   maxi=max(maxi,arr[i]);

   int hash[maxi+1]={0};
   for(int i=0;i<n;i++)
   hash[arr[i]]++;

   for(int i=0;i<n;i++){
   if(hash[arr[i]]==1){
    return arr[i];
   }
   
}
return -1;
} 
int main(){
    int n;
    cout<<"enter the number of elements:\n";
    cin>>n;
    vector<int> a(n);
    cout<<"enter thr "<<n <<" elements of the aray only 1 and 0:\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k=getsingle(a);
    cout<<"the getement that is single as me is:\n"<<k;
 return 0;
}