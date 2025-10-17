#include<bits/stdc++.h>
using namespace std;
int find_large(vector<int> arr){
    int max =arr[0];
    for(int i=0;i<arr.size();i++ ){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
int main(){
    int n;
    cout<<"enter the number of elements of the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the "<<n<<" of elemnets of the array\n";

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"the large element is: "<<find_large(arr);
}