/*Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
Reason: We are inserting N elements in the map data structure and insertion takes logM time(where M = size of the map). So this results in the first term O(N*logM). The second term is to iterate the map and search the single element. In Java, HashMap generally takes O(1) time complexity for insertion and search. In that case, the time complexity will be O(N) + O(M).

Note: The time complexity will be changed depending on which map data structure we are using. If we use unordered_map in C++, the time complexity will be O(N) for the best and average case instead of O(N*logM). But in the worst case(which rarely happens), it will be nearly O(N2).

Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.*/
#include<bits/stdc++.h>
using namespace std;
int getsingle(vector <int >arr){
   map<int,int> mp;
   int n=arr.size();
   for(int i=0;i<n;i++){
    mp[arr[i]]++;
   }
   for(auto x:mp){
    if(x.second ==1){
        return x.first;
    }
   }
   return -1;
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