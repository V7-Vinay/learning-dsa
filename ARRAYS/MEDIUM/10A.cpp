#include<bits/stdc++.h>
using namespace std;

void markrow(vector<vector<int>>&matrix,int n,int m){
    for(int i=0;i<m;i++){
        if(matrix[n][i]!=0){
            matrix[n][i]=-1;
        }
    }
}
void markcol(vector<vector<int>>&matrix,int m,int n){
 for(int i=0;i<n;i++){
        if(matrix[i][m]!=0){
            matrix[i][m]=-1;
        }
    }
}
vector<vector<int>>setmatrix(vector<vector<int>>matrix,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                markcol(matrix,j,n);
                markrow(matrix,i,m);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==-1){
              matrix[i][j]=0;
            }
        }
    }
    return matrix;
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
   mat= setmatrix(mat,n,m);
   cout<<"arranging :\n";
   for(auto& it: mat){
    for( auto& x:it){
        cout<<x<<" ";
    }
    cout<<"\n";
   }
}