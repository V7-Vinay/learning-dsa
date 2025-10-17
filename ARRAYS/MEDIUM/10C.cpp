#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>setmatrix(vector<vector<int>>matrix,int n,int m){
   int col=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if(j!=0)
                matrix[0][j]=0;
                else col=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][0]==0||matrix[0][j]==0){
              matrix[i][j]=0;
            }
        }
    }
    
        if(matrix[0][0]==0){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }
       
    if(col==0){
         for(int i=0;i<n;i++){
         matrix[i][0]=0;
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