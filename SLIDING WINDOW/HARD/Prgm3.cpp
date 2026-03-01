#include<bits/stdc++.h>
using namespace std;
string minWindowOptimal(string s, string t) {
      int freq[256]={0};
      int n=s.size(),m=t.size();
      for(char c:t){
        freq[c]++;
      }

      int l=0,r=0;
      int count=0,minlen=INT_MAX;
      int start=-1;

      while(r<s.size()){
        if(freq[s[r]]>0)count++;
        freq[s[r]]--;
        while(count==m){
            if(r-l+1<minlen){
                minlen=r-l+1;
                start=l;
            }
            freq[s[l]]++;
            if(freq[s[l]]>0){
                count--;
            }
            l++;
        }
        r++;
      }
      return start==-1?"":s.substr(start,minlen);
    }

     string minWindowBrute(string s, string t) {
        int m = s.size(), n = t.size();
        if (n > m) return "";
        vector<int>freq(256,0);
        for(char c:t){
            freq[c]++;
        }
        int minlen=INT_MAX;
        string ans="";
        for(int i=0;i<m;i++){
            vector<int>hash(256,0);int count=0;
            for(int j=i;j<m;j++){
                hash[s[j]]++;
                if(hash[s[j]]<=freq[s[j]])count++;
                if(count==n){
                    if(j-i+1<minlen){
                        minlen=j-i+1;
                        ans=s.substr(i,minlen); 
                    }
                    break;
                }
            }
        }
        return ans;
    }