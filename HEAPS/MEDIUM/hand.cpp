#include <bits/stdc++.h>
using namespace std;
bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;
        map<int,int>map1;
        for(auto num:hand)map1[num]++;

       for(auto it :map1){
       int start= it.first;
       int count=it.second;
       if(count>0){
       for(int i=0;i<groupSize;i++){
        if(map1[start+i]<count)return false;
        map1[start+i]-=count;
        }
       }
       }
        return true;
    }
int main(){
    vector<int> hand={1,2,3,6,2,3,4,7,8};
    int groupSize=3;
    cout<<isNStraightHand(hand,groupSize);
    return 0;
}