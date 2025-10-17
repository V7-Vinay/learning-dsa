/* IN A GIVEN ARRAY YOU SHOULD RETURN THE ELEMENT WHOOSE OCCURENCE  IS GREATER
THAN N/2 TIMES THE SIZE OF ARRAY HERE AS IT IS N/2 ONLY ONE CAN BE A THAT TYPE OF ELEMENT 
IN FUTURE N/3 U WILL SEE VARIATION*/

//BRUTE FORCE SOLUTION
#include<bits/stdc++.h>
using namespace std;
int greatern2(vector<int> arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
         int cnt =0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j])cnt++;
        }
        if(cnt>n/2)return arr[i];
    }
    return 0;
}
int main(){
    int n;
    cout<<"enter the number of elements in the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array(0,1,2) only:\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"the element which has occurence >(n/2) is "<< greatern2(arr);
}