#include<bits/stdc++.h>
using namespace std;

void find_large(vector<int> arr,int n){
 if (n==0||n==1) 
 cout<<"-1";
    sort(arr.begin(), arr.end());
    int s_small=arr[1],s_large=arr[n-2];
    cout<<"the second large element is :"<<s_large;
    cout<<"the second large element is :"<<s_small;

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
    find_large(arr,n);
    return 0 ;

}