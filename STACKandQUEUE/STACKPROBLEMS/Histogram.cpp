#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int area=0;
        for(int i=0;i<n;i++){
          int count=0;
          for(int j=i-1;j>=0;j--){
            if(heights[j]>=heights[i])count++;
            else
            break;
          }
           for(int j=i+1;j<n;j++){
            if(heights[j]>=heights[i])count++;
            else
            break;
          }
          area=max(area,(count+1)*heights[i]);
        }
        return area;
    }

    int largestRectangleAreaBetter(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int>leftsmall(n),rightsmall(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            leftsmall[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            rightsmall[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            int width = rightsmall[i] - leftsmall[i] + 1;
            maxA = max(maxA, heights[i] * width);
        }
        return maxA;
    }

     int largestRectangleAreaBest(vector<int>& heights) {
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
int main() {
    vector<int> heights = {2, 1, 5, 6,  7, 3, 4,3};
    cout << "Largest Rectangle Area (Brute Force): " << largestRectangleArea(heights) << endl;
    cout << "Largest Rectangle Area (Better): " << largestRectangleAreaBetter(heights) << endl;
    cout << "Largest Rectangle Area (Best): " << largestRectangleAreaBest(heights) << endl;
    return 0;
}       