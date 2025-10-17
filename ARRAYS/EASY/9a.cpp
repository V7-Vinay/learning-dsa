//union of two arrys using set it can be sorted or unsorted
//Time Complexity: O(m+n), Because at max i runs for n times and j runs for m times. When there are no common elements in arr1 and arr2 and all elements in arr1, arr2 are distinct. 

//Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 

//O(1) {If Space of union ArrayList is not considered}
#include<bits/stdc++.h>
using namespace std;
vector<int> funion(int arr1[],int arr2[],int n ,int m){
    set<int> s;
    for(int i=0;i<n;i++){
        s.emplace(arr1[i]);
    }
    for(int i=0;i<m;i++){
        s.emplace(arr2[i]);
    }
    vector<int> temp;
    for(auto &x:s)
    temp.push_back(x);
    return temp;
}
int main(){
    int n,m;
    
    cout<<"enter the number of elemnets of the array 1:\n";
    cin>>n;
    cout<<"enter the number of elemnets of the array 2:\n";
    cin>>m;

    int arr1[n],arr2[m];
    cout<<"enter the "<<n<<" of elemnets of the array\n";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
 
    cout<<"enter the "<<m<<" of elemnets of the array\n";
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
   vector<int> temp =funion(arr1,arr2,n,m);
  cout<<"after union :\n";
  for(auto it:temp)
  cout<<it<<" ";
  return 0;
}