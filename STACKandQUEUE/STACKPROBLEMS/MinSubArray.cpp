#include<bits/stdc++.h>
using namespace std;
int sumSubarrayMinsBrute(vector<int>& arr) {
        int sum=0,mod=1e9+7;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int mini=arr[i];
            for(int j=i;j<n;j++){
                mini=min(mini,arr[j]);
                sum = (sum + mini) % mod;
            }
        }
        return sum;
    }

    vector<int>findnse(vector<int>& arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i])
            st.pop();
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int>findpse(vector<int>& arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i])
            st.pop();
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
       vector<int>nse=findnse(arr);
       vector<int>psee=findpse(arr);
       int sum=0,n=arr.size(),mod=1e9+7;
       for(int i=0;i<n;i++){
        int ls=i-psee[i];
        int rs=nse[i]-i;
         long long freq = ls*rs*1LL;
            int val = (freq*arr[i]*1LL) % mod;
            sum = (sum + val) % mod;
       }
       return sum;
    }


int main(){
    vector<int>arr={3,1,2,4};
    cout<<sumSubarrayMins(arr)<<endl;
    cout<<sumSubarrayMinsBrute(arr)<<endl;
    return 0;
}