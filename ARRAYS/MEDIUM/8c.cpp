
#include<bits/stdc++.h>
using namespace std;

int longconsecutive(vector<int>arr){
    int n=arr.size();
     int longest=1;
    if(n==0)return 0;
    unordered_set<int>st;
    for(int i=0;i<n;i++)
    st.insert(arr[i]);
    for(int it:st){
       
       if(st.find(it-1)==st.end()){
        int cnt=1;
        it+=1;
        while(st.find(it)!=st.end()){
            it++,cnt++;
        }
        longest=max(longest,cnt);
       }
    }
    return longest;

}

int main(){
    int n,it;
    cout<<"enter the number of elements in the array:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array :\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"the longest consicutive sequecnce is:\n "<<longconsecutive(arr);
}