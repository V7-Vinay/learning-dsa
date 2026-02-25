#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringBrute(string s) {
        int n=s.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            vector<int>hash(256,0);
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1)break;
                hash[s[j]]=1;
                int len=j-i+1;
                maxlen=max(maxlen,len);
            }
        }
        return maxlen;
    }

 int lengthOfLongestSubstringOptimal(string s) {
       int l=0,r=0,maxlen=0;
       int hash[256];
       fill(hash, hash + 256, -1);
       int n=s.size();
       while(r<n){
        if(hash[s[r]]!=-1){
            l=max(hash[s[r]]+1,l);
        }
        int len=r-l+1;
        maxlen=max(maxlen,len);
        hash[s[r]]=r;
        r++;
       }
        return maxlen;
    }

int main(){
    string s;   
    cout<<"Enter the string: ";
    cin>>s;
    cout<<lengthOfLongestSubstringBrute(s)<<endl;
    cout<<lengthOfLongestSubstringOptimal(s)<<endl;


    return 0;
}