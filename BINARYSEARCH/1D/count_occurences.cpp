#include<bits/stdc++.h>
using namespace std;
    vector<int> find_first_and_last_occurence(vector<int>& nums, int target) {
        int start=0,n=nums.size();
        int end=n-1;
        int cnt=0;
        vector<int>ans(2,-1);

        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>=target){
                end=mid-1;
            }else{
                start=mid+1;
            }
            if(nums[mid]==target)ans[0]=mid;
        }
        start=0,end=n-1;

        while(start<=end){
           int mid=(start+end)/2;
           if(nums[mid]<=target){
            start=mid+1;
           }else{
            end=mid-1;
           }
           if(nums[mid]==target)ans[1]=mid;
        }
        return ans;
       
    }
    
    int main(){
     int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target value: ";
    cin >> target;
    vector<int> ans=find_first_and_last_occurence(nums,target);

    
    cout << "first occurrence (Binary Search) index: " << ans[0] << endl;
    cout << "Last occurrence (Binary Search) index: " << ans[1] << endl;
    if(ans[0]!=-1){
        cout<<"the number of occurence of target is:"<<ans[1]-ans[0]+1<<endl;
    }else{
        cout<<"the number of occurence of target is:"<<0<<endl;
    }

    return 0;
}