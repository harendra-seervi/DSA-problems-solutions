#include<bits/stdc++.h>
using namespace std;

// memoization (Top -Down)
// int febo(int n,vector<int>&dp){
//     if(n<=1) return n;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n]=febo(n-1,dp)+febo(n-2,dp);
// }
// void solve(){
//     int n;
//     cin>>n;
//     vector<int>dp(n+1,-1);
//     cout<<febo(n,dp)<<endl;

// }

// Tabulation (Bottom-up) + space optimizaion

void solve(){
    int n;
    cin>>n;
    int pre1=1,pre2=0;
    int curi;
    for(int i=2;i<=n;i++){
        curi=pre1+pre2;
        pre2=pre1;
        pre1=curi;
    }
    cout<<pre1<<endl;
}

    
int main(){
    solve();
return 0;
}