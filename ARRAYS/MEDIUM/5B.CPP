/*You are given an array of prices where prices[i] is the price of a given stock on an ith day.

You want to maximize your profit by choosing a single day
 to buy one stock and choosing adifferent day in the future to sell that stock.
  Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
  */

  //BRUTE FORCE SOLUTION
  #include<bits/stdc++.h>
using namespace std;
  int macpro(vector<int> arr){
    int n=arr.size();
   int maxpro=-1,minval=INT_MAX;
   for(int i=0;i<n;i++){
    minval= min(arr[i],minval);
    maxpro=max(maxpro,(arr[i]-minval));
   }
   return maxpro;
  }
  int main(){
    int n;
    cout<<"enter the number of elements in the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array :\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"the amx profit u can get is:\n"<<macpro(arr);
  }