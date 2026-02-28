#include<bits/stdc++.h>
using namespace std;
int maxScoreOptimal(vector<int>& cardPoints, int k) {
        int total=0;
        for(int i=0;i<k;i++){
            total+=cardPoints[i];
        }
        int maxpoints=total,n=cardPoints.size();
        for(int i=0;i<k;i++){
            total-=cardPoints[k-1-i];
            total+=cardPoints[n-1-i];
            maxpoints=max(total,maxpoints);
        }
        return maxpoints;
    }