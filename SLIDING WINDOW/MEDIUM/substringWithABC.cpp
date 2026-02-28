#include<bits/stdc++.h>
using namespace std;
int numberOfSubstringsBrute(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int hash[3]={0};
            for(int j=i;j<s.size();j++){
                hash[s[j]-'a']++;
                if(hash[0]!=0&&hash[1]!=0&&hash[2]!=0){
                    ans++;
                }
            }
        }
        return ans;
    }

      int numberOfSubstringsOptimal(string s) {
        int lastseen[3]={-1,-1,-1},cnt=0;
       for(int i=0;i<s.size();i++){
        lastseen[s[i]-'a']=i;
        if(lastseen[0]!=-1&&lastseen[1]!=-1&&lastseen[2]!=-1)
        cnt=cnt+1+ min({lastseen[0],lastseen[1],lastseen[2]});
       }
       return cnt;
    }