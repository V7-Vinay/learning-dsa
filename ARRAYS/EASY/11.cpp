#include<bits/stdc++.h>
using namespace std;
int getconsecuttive(vector<int> nums){
    int cnt=0,mcnt=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            cnt++;
        }else{
            cnt=0;
        }
        mcnt =max(mcnt,cnt);
    }
    return mcnt;
}
int main(){
    int n;
    cout<<"enter the number of elements:\n";
    cin>>n;
    vector<int> a(n);
    cout<<"enter thr "<<n <<" elements of the aray only 1 and 0:\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int maxo=getconsecuttive(a);
    cout<<"the number of times consecutively 1 arrive is:  "<<maxo;
}