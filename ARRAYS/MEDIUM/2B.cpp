 /*you have given a arrayt with only 0,1,2
 you have to sort them */
  //here for the optimal solution we are using the dutch national flag algorithm
  //you can see the algo intituion the tuf

   /*you have given a arrayt with only 0,1,2
 you have to sort them */
#include<bits/stdc++.h>
using namespace std;
void sort_three(vector<int> &arr){
   int low=0,mid=0,n=arr.size(),high=arr.size()-1;
   while(mid<=high){
    if(arr[mid]==0){
        swap(arr[low],arr[mid]);
        low++;
        mid++;
    }else if(arr[mid]==1){
        mid++;
    }else{
        swap(arr[mid],arr[high]);
        high--;
    }
   }
   cout<<"the sorted array is: \n";
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
}
int main(){
    int n;
    cout<<"enter the number of elements in the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array(0,1,2) only:\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort_three(arr);
       

}