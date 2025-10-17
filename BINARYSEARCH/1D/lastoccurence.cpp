#include<bits/stdc++.h>
using namespace std;
int find_last_occurence_navie(vector<int> nums,int target){
int res=-1;
for(int i=nums.size()-1;i>=0;i--){
    if(nums[i]==target){
        res=i;return res;
        break;
    }
}
return res;
}

int find_last_occurence_binary_search(vector<int> nums,int target){
int res=-1;
int start=0,n=nums.size();
int end=n-1;
while(start<=end){
    int mid=(start+end)/2;
    if(nums[mid]<=target){
        start=mid+1;
    }else{
        end=mid-1;
    }
    if(nums[mid]==target)res=mid;
}
return res;
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

    int res1 = find_last_occurence_navie(nums, target);
    int res2 = find_last_occurence_binary_search(nums, target);

    cout << "Last occurrence (Naive) index: " << res1 << endl;
    cout << "Last occurrence (Binary Search) index: " << res2 << endl;

    return 0;
}