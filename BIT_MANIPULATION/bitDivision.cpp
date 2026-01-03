#include <bits/stdc++.h>
using namespace std;
 int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;
        if(divisor==1)return dividend;
        if(dividend==INT_MIN&&divisor==-1)return INT_MAX;

        long long n= llabs((long long )dividend);
        long long d= llabs((long long )divisor);
        
        int sign = divisor>0==dividend>0;
        long long ans =0;
        while(n>=d){
            long long temp=d;
            long long multiple=1;
            while((temp<<1)<=n){
                temp<<=1;
                multiple<<=1;
            }
            n-=temp;
            ans+=multiple;
        }
    
        return sign?ans:-ans;

    }
int main() {
    int dividend = 1089;  
    int divisor = 3;
    cout << divide(dividend, divisor) << endl; // Output: 3
    return 0;   
}