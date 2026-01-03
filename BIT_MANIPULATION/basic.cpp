#include<bits/stdc++.h>
using namespace std;
bool checkITHbitSetleftshift(int n, int i) {
    return ((n&1<<i)!=0);
}
bool checkITHbitSetrightshift(int n, int i) {
    return ((n>>i&1)!=0);
}
void setITHbit(int &n, int i) {
    n=n|(1<<i);
}
void setorUnsetITHbit(int &n, int i) {
    n=n^(1<<i);
}
int unsetLastsetbit(int n){
    return (n&(n-1));
}
int setLastunsetbit(int n){
    return (n|(n+1));
}
bool powerof2(int n){
    return ((n&(n-1))==0);
}
int countsetbitsKernighans(int n){
    int count=0;
    while(n){
        count++;
        n=n&(n-1);
    }
    return count;
}
int countsetbits(int n){
    int count=0;
   while(n>1){
    if(n&1){
        count++;
    }
    n>>=1;
   }
   if(n==1)
    count++;
    return count;
}
int main() {
    int n=8; //0101
    int i=2;
    int k=10;
    cout<<checkITHbitSetleftshift(n,i)<<endl; //1
    cout<<checkITHbitSetrightshift(n,i)<<endl; //1
    setITHbit(n,1); //0111
    cout<<n<<endl;
    setorUnsetITHbit(n,2); //0011
    cout<<n<<endl;
    cout<<unsetLastsetbit(n)<<endl; //0010
    cout<<setLastunsetbit(n)<<endl; //0011
    cout<<powerof2(n)<<endl; //0
    cout<<countsetbits(k)<<endl; //2
    cout<<countsetbitsKernighans(k)<<endl; //2
    return 0;
}