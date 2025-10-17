#include<bits/stdc++.h>
using namespace std;
int number_sub_array_with_sum_k(vector<int>ans,int k){
    int n=ans.size();int cnt=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=ans[j];
            if(sum==k)cnt++;
            
        }
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