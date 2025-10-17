#include<bits/stdc++.h>
using namespace std;
string twosum(vector<int> arr,int target){
    sort(arr.begin(),arr.end());
   int  left=0;
    int right=arr.size()-1;
    while (left<right)
    {       
        int sum=arr[left]+arr[right];
        if(sum==target){
            return"yes";
          }else if(sum<target)left++;
          else right--;
    }
    return "no";
}
int main(){
    int n,it,k;
    cout<<"enter the number of elements in the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array:\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"enter the target to find:\n";
    cin>>k;
    cout<<twosum(arr,k)<<"  the array contains the target  "<<k<<endl;
}