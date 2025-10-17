#include<bits/stdc++.h>
using namespace std;
vector<int> spiral(vector<vector<int>>mat){
    int left=0,top=0;
    int m=mat[0].size();
    int n=mat.size();
    vector<int>ans;
    int right=m-1,bottom=n-1;
    while(top<=bottom&&left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                  ans.push_back(mat[i][left]);   
            }
             left++;
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
   vector<int>ans;
   cout<<"after spiral :";
   ans=spiral(mat);
   cout<<"the ans  is :\n";
  
    for( auto& x:ans){
        cout<<x<<" ";
    }
    
   
}