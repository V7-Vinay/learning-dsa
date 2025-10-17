// left rotste array by on pos
#include<bits/stdc++.h>
using namespace std;
void left(int arr[],int n){
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
}