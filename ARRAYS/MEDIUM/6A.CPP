/*  IN AN ARRAY PLACE THE POSITIVE NUMBERS IN EVEN AND 
NEGATIVE IN THE OOD POSITION IN THE SAME ORDER IN WHICH THEY PRESENT IN THE ARRAY*/
#include<bits/stdc++.h>
using namespace std;
vector<int> posnegplace(vector<int> arr){
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0)pos.push_back(arr[i]);
      else  neg.push_back(arr[i]);
    }
    for(int i=0;i<(arr.size()/2);i++){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    } 
    return arr;
}
int main(){
    int n,it;
    cout<<"enter the number of elements in the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array :\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"after arrangening the array we get";
    arr=posnegplace(arr);
    for(int i:arr)
    cout<<i<<" ";
}