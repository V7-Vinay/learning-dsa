#include <bits/stdc++.h>
using namespace std;
 int characterReplacementBrute(string s, int k) {
        int maxi=0;
        for(int i=0;i<s.size();i++){
            int hash[26]={0},maxfreq=0,count=0;
            for(int j=i;j<s.size();j++){
                hash[s[j]-65]++;
                maxfreq=max(hash[s[j]-65],maxfreq);
                count=j-i+1-maxfreq;
                if(count<=k){
                    maxi=max(maxi,j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxi;
    } 

    int characterReplacementOptimal(string s, int k) {
        int l=0,r=0,maxlen=0,maxfreq=0;
        int hash[26]={0};
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            while((r-l+1)-maxfreq>k){
                hash[s[l]-'A']--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }

int main(){
    string s;   
    int k;             
    cout<<"Enter the string: ";
    cin>>s;
    cout<<"Enter the value of k: "; 
    cin>>k;
    cout<<"The length of the longest substring that can be obtained by replacing at most k characters is: "<<characterReplacementBrute(s,k)<<endl;
    cout<<"The length of the longest substring that can be obtained by replacing at most k characters is: "<<characterReplacementOptimal(s,k)<<endl;
    return 0;
}