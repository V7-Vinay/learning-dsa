 vector<int> topKFrequentBrute(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto num:nums)
        mp[num]++;
        vector<int>ans;
        for(int i=0;i<k;i++){
            int gnum=0,gfreq=0;
              for (auto it = mp.begin(); it != mp.end(); it++) {
                if(it->second > gfreq){
                    gfreq = it->second;
                    gnum = it->first;
                }
              }
              ans.push_back(gnum);
              mp.erase(gnum);     
               }
            return ans;
    }

      vector<int> topKFrequentOptimal(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        map<int,int>mp;
        for(auto num:nums)
        mp[num]++;

        for(auto it:mp)
        pq.push({it.second,it.first});
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }