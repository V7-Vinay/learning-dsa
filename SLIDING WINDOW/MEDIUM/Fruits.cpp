#include <bits/stdc++.h>
using namespace std; 
  int FruitCountBrute(vector<int>& fruits){
    int maxCount=0;
    for(int i=0;i<fruits.size();i++){
        unordered_set<int>st;
        for(int j=i;j<fruits.size();j++){
            st.insert(fruits[j]);
            if(st.size()>2)break;
            int count=j-i+1;
            maxCount=max(maxCount,count);
        }
     }
        return maxCount;
  }

   int FruitCountOptimal(vector<int>& fruits){
    int maxCount=0;
    int l=0,r=0;
    unordered_map<int,int>mp;
   for( r=0;r<fruits.size();r++){
    mp[fruits[r]]++;
    while(mp.size()>2){
        mp[fruits[l]]--;
        if(mp[fruits[l]]==0){
            mp.erase(mp[fruits[l]]);
        }
        l++;
    }
    maxCount=max(maxCount,r-l+1);
   }
    return maxCount;
  }

  int FruitCountOptimal2(vector<int>& fruits){
    int maxCount=0;
    int l=0,r=0;
    unordered_map<int,int>mp;
   for( r=0;r<fruits.size();r++){
    mp[fruits[r]]++;
    if(mp.size()>2){
        mp[fruits[l]]--;
        if(mp[fruits[l]]==0){
            mp.erase(mp[fruits[l]]);
        }
        l++;
    }
    maxCount=max(maxCount,r-l+1);
   }
    return maxCount;
  }

int main(){
    int n;                
    cout<<"Enter the size of the array: ";  
    cin>>n;
    vector<int>fruits(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>fruits[i];
    }   
    cout<<"brute "<<FruitCountBrute(fruits)<<endl;
    cout<<"optimal "<<FruitCountOptimal(fruits)<<endl;  
    cout<<"optimal2 "  <<FruitCountOptimal2(fruits)<<endl;
    return 0;
}
