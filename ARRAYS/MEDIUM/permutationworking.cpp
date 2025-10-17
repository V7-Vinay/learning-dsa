
#include<bits/stdc++.h>
using namespace std;
vector<int> next_permutation(vector<int>arr){
    int n=arr.size();
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
             index =i;
            break;
        }
    }
        if(index==-1){
            (reverse(arr.begin(),arr.end()));
            return arr;
        }
        for(int i=n-1;i>index;i--){
            if(arr[i]>arr[index]){
                swap(arr[i],arr[index]);
                break;
            }
        }
        reverse(arr.begin()+index+1,arr.end());
    
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
    cout<<"the next permutation of the given number is:\n";
   vector<int> arr2=next_permutation(arr);
   for(int x:arr2)
   cout<<x<<" ";
}
