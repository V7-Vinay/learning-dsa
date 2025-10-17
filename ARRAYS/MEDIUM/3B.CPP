/* IN A GIVEN ARRAY YOU SHOULD RETURN THE ELEMENT WHOOSE OCCURENCE  IS GREATER
THAN N/2 TIMES THE SIZE OF ARRAY HERE AS IT IS N/2 ONLY ONE CAN BE A THAT TYPE OF ELEMENT 
IN FUTURE N/3 U WILL SEE VARIATION*/

//OPTIMAL SOLUTION USING MOORE'S VOTING ALGORITHM  INTITUTION TUF U CAN SEE
#include<bits/stdc++.h>
using namespace std;
int greatern2(vector<int> arr){
    int n=arr.size();
    int ele=0,cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            ele=arr[i];
            cnt=1;  
        }else if(arr[i]==ele){
            cnt++;
        }else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==ele)cnt1++;
    }
    if(cnt1>n/2)return ele;
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