#include <bits/stdc++.h>
using namespace std;
int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>map;
        for(auto c:tasks){
            map[c]++;
        }
        priority_queue<int,vector<int>>pq;
        for(auto c:map){
            pq.push(c.second);
        }
        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            int cycle=n+1;
            int i=0;
            while(i<cycle&&!pq.empty()){
                int cnt=pq.top();
                pq.pop();
                cnt--;
                if(cnt>0)temp.push_back(cnt);
                i++;
                time++;
            }
            for(auto val:temp){
                pq.push(val);
            }
            if(pq.empty())break;
            time+=(cycle-i);
        }
        return time;
    }
int main(){
    vector<char> tasks={'A','A','A','B','B','B'};
    int n=2;
    cout<<leastInterval(tasks,n);
    return 0;
}