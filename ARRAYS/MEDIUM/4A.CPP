/* IN A GIVEN ARRAY WITH POS AND NEG ELEMENTS PRESENT WE NEED TO FIND THE 
SUB ARRAY WHICH GIVES THE MAXIMUM SUM*/

//BRUTE FORCE
#include<bits/stdc++.h>
using namespace std;
int  maxsum(vector<int>arr){
  int n=arr.size(),maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}
int main(){
    int n;
    cout<<"enter the number of elements in the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array :\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"the max sum of a sub array is:\n"<<maxsum(arr);
}