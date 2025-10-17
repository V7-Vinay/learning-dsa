#include<bits/stdc++.h>
using namespace std;
int l(vector<int> arr,int n){
    if(n<2)
    cout<<"-1";
    int s=INT_MAX,ss=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<s){
            ss=s;
            s=arr[i];
        }else if(arr[i]<ss&&arr[i]!=s){
            ss=arr[i];
        }
    }
return ss;
}
int s(vector<int> arr,int n){
    if(n<2)
    cout<<"-1";
    int l=INT_MIN,ll=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>l){
            ll=l;
            l=arr[i];
        }else if(arr[i]>ll&&arr[i]!=l){
            ll=arr[i];
        }
    }
return ll;
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
    cout<<"the second large element is : "<<l(arr,n);
    cout<<"\nthe second small element is :"<<s(arr,n);

    return 0 ;

}