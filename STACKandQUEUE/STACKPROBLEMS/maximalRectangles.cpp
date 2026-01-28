#include<bits/stdc++.h>
using namespace std;
 int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),maxA=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int nse =i;
                int element=heights[st.top()];
                st.pop();
                int pse=!st.empty()?st.top():-1;
                maxA=max(maxA,(nse-pse-1)*element);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int element=heights[st.top()];st.pop();
            int pse=!st.empty()?st.top():-1;
            maxA=max(maxA,(nse-pse-1)*element);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),maxA=0;

        vector<vector<int>>prefix(n,vector<int>(m));
        for(int i=0;i<m;i++){
            int x=0;
            for(int j=0;j<n;j++){
                if(matrix[j][i]=='1'){
                    x++;
                    prefix[j][i]=x;
                }else{
                    x=0;
                    prefix[j][i]=x;
                }
            }
        }
        for(int j=0;j<n;j++){
            maxA=max(maxA,largestRectangleArea(prefix[j]));
        }
        return maxA;
    }
int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };  
    cout << "Maximal Rectangle Area: " << maximalRectangle(matrix) << endl;
    return 0;
}