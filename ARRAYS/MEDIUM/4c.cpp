/* IN A GIVEN ARRAY WITH POS AND NEG ELEMENTS PRESENT WE NEED TO FIND THE 
SUB ARRAY WHICH GIVES THE MAXIMUM SUM*/

//OPTIMAL SOULTION : USING KADANE'S ALGORITHM  HERE WE ALSO PRINT THE SUB ARRAY WHICH GIVES MAXIMUM SUM
#include<bits/stdc++.h>
using namespace std;
int  maxsum(vector<int>arr){
  int n=arr.size(),maxi=INT_MIN,sum=0;
  int start,ansstart,ansend;
   for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum<0){
        sum=0;
        start=i;
    }
    else if(sum>maxi){
        maxi=sum;   
        ansstart=start  ;
        ansend=i;  
    }
   }
   for(int i=ansstart;i<=ansend;i++)
   cout<<arr[i]<<" ";
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
    cout<<"\nthe max sum of a sub array is:\n"<<maxsum(arr);
}