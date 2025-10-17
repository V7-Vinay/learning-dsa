#include<bits/stdc++.h>
using namespace std;
int number_sub_array_with_sum_k(vector<int>ans,int k){
    int n=ans.size();
    int cnt=0,sum=0;
    map <int,int>mpp;
    mpp[0]=1;

    for(int i=0;i<n;i++){
        sum+=ans[i];
      int req=sum-k;
      cnt+=mpp[req];
      mpp[sum]+=1;
    }   
    return cnt;
}
int main(){
    int n,key;
    cout<<"enter the number of elements in the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array :\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"enter the target element:\n";
    cin>>key;
    cout<<"the no of sub array with sum as key :\n";
    cout<<number_sub_array_with_sum_k(arr,key);
}