#include<bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>>&m){
    int n=m.size();
    vector<int>knowme(n,0);
    vector<int>iknow(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]==1){
               iknow[i]++;
               knowme[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(knowme[i]==n-1 &&iknow[i]==0)return i;   
    }
    return -1;
}
int celebrityOptimal(vector<vector<int>>&m){
    int n=m.size();
    int top=0,down=n-1;
    while(top<down){
        if(m[top][down]==1)top++;
        else if(m[down][top]==1)down--;
        else{
            top++;
            down--;
        }
    }
    if(top>down)
    return -1;
    for(int i=0;i<n;i++){
        if(i!=top){
            if(m[top][i]==1||m[i][top]==0){
                return -1;
            }
        }
    }
    return top;
}
int main(){
    vector<vector<int>>m={{0,1,0,1},
                          {0,0,0,1},
                          {0,1,0,1},
                          {0,0,0,0}};
    int celeb=celebrity(m);
    if(celeb==-1)cout<<"No Celebrity"<<endl;
    else cout<<"Celebrity is: "<<celeb<<endl;
    int celebOpt=celebrityOptimal(m);
    if(celebOpt==-1)cout<<"No Celebrity (Optimal)"<<endl;
    else cout<<"Celebrity is: "<<celebOpt<<" (Optimal)"<<endl;
    return 0;
}