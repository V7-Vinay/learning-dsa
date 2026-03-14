class MedianFinderBrute {
    vector<int>nums;
public:
    MedianFinderBrute() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%2==1)return nums[n/2];
         return (nums[n/2]+nums[n/2-1])/2.0;
    }
};

class MedianFinderOptimal {
    priority_queue<int,vector<int>,greater<int>>minheap;
    priority_queue<int>maxheap;
public:
    MedianFinderOptimal() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size())
        return (minheap.top()+maxheap.top())/2.0;
        return maxheap.top();
    }
};