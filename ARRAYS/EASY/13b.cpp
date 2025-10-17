#include<bits/stdc++.h>
using namespace std;
int sublen(vector<int> arr ,long long k){
    map<long long,int>summap;
    int maxlen=0,sum=0;
    for(int i=0;i<arr.size();i++ ){
     sum+=arr[i];
     if(sum==k){
        maxlen=max(maxlen,i+1);
     }
     long long rem=sum-k;
     if(summap.find(rem)!=summap.end()){
        int len =i-summap[rem];
        maxlen=max(maxlen,len);
     }
     if(summap.find(rem)==summap.end()){
        summap[sum]=i;
     }
    }
    return maxlen;
}
int main() {
    int n;long long key;
    cout << "Enter the number of elements in the array:\n";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the " << n << " elements of the array:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key sum to search:\n";
    cin >> key;
    int k=sublen(arr,key);
    cout<<"the length of the max len of sub array that gives "<<key<<"  sum is :\n"<<k;
    return 0;
}