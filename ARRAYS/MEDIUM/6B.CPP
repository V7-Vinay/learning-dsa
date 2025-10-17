/*  IN AN ARRAY PLACE THE POSITIVE NUMBERS IN EVEN AND 
NEGATIVE IN THE OOD POSITION IN THE SAME ORDER IN WHICH THEY PRESENT IN THE ARRAY*/

//OPTIMAL SOLUTION
#include<bits/stdc++.h>
using namespace std;
vector<int> posnegplace(vector<int> arr){
    vector<int >aa(arr.size());int pos=0,neg=1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            aa[pos]=(arr[i]);
            pos+=2;
        }else{
            aa[neg]=(arr[i]);
            neg+=2;
        }
    }
    return aa;
}
int main(){
    int n,it;
    cout<<"enter the number of elements in the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array :\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"after arrangening the array we get";
    arr=posnegplace(arr);
    for(int i:arr)
    cout<<i<<" ";
}