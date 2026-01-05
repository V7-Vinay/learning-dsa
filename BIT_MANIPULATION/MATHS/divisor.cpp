#include<bits/stdc++.h>
using namespace std;
vector<int> findDivisorsBrute(int n){
    vector<int> divisors;
    for(int i=1;i<=n/2;i++){
        if(n%i==0){
            divisors.push_back(i);
        }
    }
    divisors.push_back(n);
    return divisors;    
}
vector<int> findDivisorsOptimal(int n){
    vector<int> divisors;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            divisors.push_back(i);
            if(i!=n/i){
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(),divisors.end());
    return divisors;    
}
int main(){
    int n;
    cin>>n;
    vector<int> divisorsBrute=findDivisorsBrute(n);
    cout<<"Brute Force Divisors: ";
    for(auto div:divisorsBrute){
        cout<<div<<" ";
    }
    cout<<endl;
    vector<int> divisorsOptimal=findDivisorsOptimal(n);
    cout<<"Optimal Divisors: ";
    for(auto div:divisorsOptimal){
        cout<<div<<" ";
    }
    cout<<endl;
    return 0;
}