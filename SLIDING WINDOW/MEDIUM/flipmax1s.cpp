#include <bits/stdc++.h>
using namespace std;
 int longestOnesBrute(vector<int>& nums, int k) {
        int maxlen=0,n=nums.size();
        for(int i=0;i<n;i++){
            int len=0,x=k;
            for(int j=i;j<n;j++){
                if(nums[j]==0){
                    if(x>0){
                        x--;
                    }else{
                        break;
                    }  
                }
                len=j-i+1;
            }
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }

    int longestOnesOptimal(vector<int>& nums, int k) {
        int maxlen=0,n=nums.size();
        int l=0,r=0,cnt=0;
        while(r<n){
          if(nums[r]==0){
            cnt++;
          }
          if(cnt>k){
            if(nums[l]==0){
                cnt--;
            }
            l++;
          }
          maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
int main(){
    int n,k;                
    cout<<"Enter the size of the array: ";  
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }   
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<longestOnesBrute(nums,k)<<endl;
    cout<<longestOnesOptimal(nums,k)<<endl;


    return 0;
}   


