 /*you have given a arrayt with only 0,1,2
 you have to sort them */
#include<bits/stdc++.h>
using namespace std;
void sort_three(vector<int> &arr){
    int count0=0,count2=0,count1=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0)count0++;
        else if(arr[i]==1)count1++;
        else count2++;
    }
    for(int i=0;i<count0;i++)arr[i]=0;
    for(int i=count0;i<count0+count1;i++)arr[i]=1;
    for(int i=count0+count1;i<arr.size();i++)arr[i]=2;
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