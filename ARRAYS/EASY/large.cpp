#include<bits/stdc++.h>
using namespace std;

int find_large(vector<int> &arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size()-1];
}
int main(){
    int n;
    cout<<"enter the number of elemnets of the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the "<<n<<" of elemnets of the array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"the largest element is "<<find_large(arr);
    return 0 ;

}