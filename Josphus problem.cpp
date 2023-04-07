#include<bits/stdc++.h>
using namespace std;

int jos(int n,int k){
    if(n==1){
        return 0;
    }
    return ((jos(n-1,k)+k)%n);
}
int main() {
    int n;
    cin>>n;
    // 0 se start hoga counting yaad rakhna
    int k; cin>>k;
    cout<<jos(n,k)<<endl;
    return 0;
}