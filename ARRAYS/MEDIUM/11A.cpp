#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>rotatemat(vector<vector<int>>matrix,int n,int m){
   vector<vector<int>> ans(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][n-1-i]=matrix[i][j];
        }
    }
    return ans;
}

int main(){
    int n,m;
    
    cout<<"enter the number of rows and columns:\n";
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    cout<<"enter the elements to the matrix:\n";
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
   cout<<"the matrix is :\n";
   for(auto& it: mat){
    for( auto& x:it){
        cout<<x<<" ";
    }
    cout<<"\n";
   }
   cout<<"after rotation:";
   mat=rotatemat(mat,n,m);
   cout<<"the matrix is :\n";
   for(auto& it: mat){
    for( auto& x:it){
        cout<<x<<" ";
    }
    cout<<"\n";
   }
}