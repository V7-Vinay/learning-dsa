#include<bits/stdc++.h>
using namespace std;
int getsub(vector <int >a,int k)
{
    int n=a.size();
    int left =0,right=0;
    int sum=a[0],maxi=0;
    while (right<n)
    {
        while(left<=right&&sum>k){
            sum-=a[left];
            left++;
        }
            if (sum==k){
                maxi=max(maxi,right-left+1);
            }
            right++;
            if(right<n)
            sum+=a[right];
        
    }
    return maxi;
}
int main() {
    int n;int key;
    cout << "Enter the number of elements in the array:\n";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the " << n << " elements of the array:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key sum to search:\n";
    cin >> key;
    int k=getsub(arr,key);
    cout<<"the length of the max len of sub array that gives "<<key<<"  sum is :\n"<<k;
    return 0;
}