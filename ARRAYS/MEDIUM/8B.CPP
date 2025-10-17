
#include<bits/stdc++.h>
using namespace std;

int longconsecutive(vector<int>arr){
    int n=arr.size();
    if(n==0)return 0;
    sort(arr.begin(),arr.end());
    int longe=1;
    int lastsmall=INT_MIN;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i-1]==lastsmall){
            cnt++;
            lastsmall=arr[i];
        }else if(arr[i]!=lastsmall){
            lastsmall=arr[i];
            cnt=1;
        }
        longe=max(longe,cnt);
    }
    return longe;
    

}

int main(){
    int n,it;
    cout<<"enter the number of elements in the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array :\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"the longest consicutive sequecnce is:\n "<<longconsecutive(arr);
}