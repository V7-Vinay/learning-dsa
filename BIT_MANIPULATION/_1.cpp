//Count number of bits to be flipped to convert A to B
#include<bits/stdc++.h>
using namespace std;
int countBitsToFlip(int a ,int b){
    int count=0;
    int num=a^b;
    while(num){
        count++;
        num=num&(num-1);
    }
    return count;
}
int main() {
    int a=10; //1010
    int b=20; //10100
    cout<<countBitsToFlip(a,b)<<endl; //4
    return 0;
}