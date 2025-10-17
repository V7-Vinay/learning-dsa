/*LEADER IN THE ARRAY PROBLEM*/
// Given an array, print all the elements which are leaders.
// A Leader is an element that is greater than all of the elements on its right side in the array.

//OPTIMAL SOLUTION

#include<bits/stdc++.h>
using namespace std;
vector<int >leader(vector<int>arr){
    int n=arr.size();
    vector<int >ar;
    ar.push_back(arr[n-1]);
    int large=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]>large){
            large=arr[i];
            ar.push_back(arr[i]);
        }
    }
    reverse(ar.begin(),ar.end());
    return ar;
}

int main(){
    int n,it;
    cout<<"enter the number of elements in the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array :\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"the leaders are:\n";
    arr=leader(arr);
    for(int x:arr)cout<<x<<" ";
   
}