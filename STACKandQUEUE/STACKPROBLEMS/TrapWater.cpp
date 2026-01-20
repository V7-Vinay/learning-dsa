#include<bits/stdc++.h>
using namespace std;
int trapBrute(vector<int>& height) {
        int n=height.size();
        int res=0;
        for(int i=0;i<n;i++){
            int leftmax=0,rightmax=0;
            for(int j=i;j>=0;j--){
                if(height[j]>leftmax)leftmax=height[j];
            }
            for(int j=i;j<n;j++){
                if(height[j]>rightmax)rightmax=height[j];
            }
            res+=min(leftmax,rightmax)-height[i];
        }
        return res;
}

 int trapBetter(vector<int>& height) {
        int n=height.size();
        int res=0;
        vector<int> prefix(n,0);
        vector<int> sufix(n,0);
        int leftmax=0,rightmax=0;
       for(int i=0;i<n;i++){
        if(height[i]>leftmax){
            leftmax=height[i];
        }
        prefix[i]=leftmax;
       }
       for(int i=n-1;i>=0;i--){
        if(height[i]>rightmax){
            rightmax=height[i];
        }
        sufix[i]=rightmax;
       }
        for(int i=0;i<n;i++){
       res+= min(prefix[i],sufix[i])-height[i];
       }
        return res;
    }


      int trapOptimal(vector<int>& height) {
        int n=height.size();
        int res=0;
        int l=0,r=n-1;
        int leftmax=0,rightmax=0;
       while(l<r){
        if(height[l]<=height[r]){
            if(height[l]>=leftmax)leftmax=height[l];
            else
            res+=leftmax-height[l];
            l++;
        }else{
            if(height[r]>=rightmax)rightmax=height[r];
            else
            res+=rightmax-height[r];
            r--;
        }
       }
        return res;
    }
int main(){
    vector<int> height={0,1,0,2,1,0,3,1,0,1,2};
    cout<<trapBrute(height)<<endl;
    cout<<trapBetter(height)<<endl;
    cout<<trapOptimal(height)<<endl;    
    return 0;
}