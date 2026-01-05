#include<bits/stdc++.h>
using namespace std;
bool isPrimeOptimal(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> findPrimeDivisorsBrute1(int n){
    vector<int> primeDivisors;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            if(isPrimeOptimal(i)){
                primeDivisors.push_back(i);
            }
        }
    }
    return primeDivisors;    
}

vector<int> findPrimeDivisorsBrute2(int n){
    vector<int> primeDivisors;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(isPrimeOptimal(i)){
                primeDivisors.push_back(i);
            }
            if(i!=n/i && isPrimeOptimal(n/i)){
                primeDivisors.push_back(n/i);
            }
        }
    }
    sort(primeDivisors.begin(),primeDivisors.end());
    return primeDivisors;    
}

vector<int> findPrimeDivisorsOptimal(int n){
    vector<int> primeDivisors;
   for(int i=2;i<=sqrt(n);i++){//if loop from from 2 to n time complexity will be more when n is prime number
    if(n%i==0){
        primeDivisors.push_back(i);
        while(n%i==0){  
            n=n/i;
        }   
    }
   }    
    if(n>1){
          primeDivisors.push_back(n);
    }
    return primeDivisors;
}

int main(){
    int n;
    cin>>n;
    vector<int> primeDivisorsBrute1=findPrimeDivisorsBrute1(n);
    cout<<"Brute Force Prime Divisors Method 1: ";
    for(auto div:primeDivisorsBrute1){
        cout<<div<<" ";
    }
    cout<<endl;
    vector<int> primeDivisorsBrute2=findPrimeDivisorsBrute2(n);
    cout<<"Brute Force Prime Divisors Method 2: ";
    for(auto div:primeDivisorsBrute2){
        cout<<div<<" ";
    }
    cout<<endl;
    vector<int> primeDivisorsOptimal=findPrimeDivisorsOptimal(n);
    cout<<"Optimal Prime Divisors: ";
    for(auto div:primeDivisorsOptimal){
        cout<<div<<" ";
    }
    cout<<endl;
    return 0;
}