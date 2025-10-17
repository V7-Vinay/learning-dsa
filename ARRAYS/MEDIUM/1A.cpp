// medium question-1
// the two sum problem ckecking if the pair of elements which sums upto to k
// present in the given array
//varient-1 returns yes and no , varient-2 returns the position of the two elements

//BRUTE FORCE SOLUTION FOR VARIENT 1 AND 2
#include<bits/stdc++.h>
using namespace std;
string twosum(vector<int> arr,int target){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==target)return "yes";
        }
    }
    return "no";
}
vector<int> two_sum(vector<int> arr,int target){
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==target){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
            }
        }
    }
    return {-1,-1};
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
    cout<<"the target found at position :\n";
   vector<int>ans=two_sum(arr,k);
    cout<<ans[0]<<"  "<<ans[1];
}