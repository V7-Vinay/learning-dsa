/*LEADER IN THE ARRAY PROBLEM*/
// Given an array, print all the elements which are leaders.
// A Leader is an element that is greater than all of the elements on its right side in the array.

//BRUTE FORCE

#include<bits/stdc++.h>
using namespace std;
vector<int >leader(vector<int>arr){
    int n=arr.size();
    vector<int >ar;

    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
            flag=1;
            break;
        }
        }
        if(flag==0)ar.push_back(arr[i]);
    }
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