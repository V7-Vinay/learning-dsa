/*Time Complexity: O(N), where N = size of the array.
Reason: We are iterating the array only once.

Space Complexity: O(1) as we are not using any extra space. */
//best solution for 12.cpp
#include<bits/stdc++.h>
using namespace std;
int getsingle(vector <int >arr){
    int xxr=0,n=arr.size();
    for(int i=0;i<n;i++)
    xxr^=arr[i];
    return xxr;
} 
int main(){
    int n;
    cout<<"enter the number of elements:\n";
    cin>>n;
    vector<int> a(n);
    cout<<"enter thr "<<n <<" elements of the aray only 1 and 0:\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k=getsingle(a);
    cout<<"the getement that is single as me is:\n"<<k;
 return 0;
}