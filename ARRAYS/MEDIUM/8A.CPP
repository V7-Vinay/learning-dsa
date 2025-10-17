
#include<bits/stdc++.h>
using namespace std;
bool isliner(vector<int> a,int k){
    for(int i=0;i<a.size();i++){
        if(a[i]==k)return true;
    }return false;
}
int longconsecutive(vector<int>arr){
    int n=arr.size(),longe=1;
    for(int i=0;i<n;i++){
     int   x=arr[i];
       int  cnt=1;
        while(isliner(arr,x+1)==true){
            x+=1;
            cnt+=1;
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