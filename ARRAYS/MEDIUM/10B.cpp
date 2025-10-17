#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>setmatrix(vector<vector<int>>matrix,int n,int m){
   vector<int>rowmark(n,0);
   vector<int>colmark(m,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                rowmark[i]=1;
                colmark[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rowmark[i]==1||colmark[j]==1){
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