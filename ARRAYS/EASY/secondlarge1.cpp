#include<bits/stdc++.h>
using namespace std;
void fun(vector<int> arr,int n){
    if(n<2)
    cout<<"-1";
    int small=INT_MAX,ss_small=INT_MAX;
    int large=INT_MIN,ss_large=INT_MIN;
    int i;
    for(i=0;i<n;i++){
        small=min(small,arr[i]);
        large=max(large,arr[i]);
    }
    for(i=0;i<n;i++){
        if(arr[i]<ss_small&&arr[i]!=small){
            ss_small=arr[i];
        }
        if(arr[i]>ss_large &&arr[i]!=large){
            ss_large=arr[i];
        }
    }
    cout<<"the second large element is :"<<ss_large;
    cout<<"the second small element is :"<<ss_small;

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
    fun(arr,n);
    return 0 ;

}