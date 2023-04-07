#include<bits/stdc++.h>
using namespace std;
    
/*
  Think twice before code
*/
// count paths
// memoization
// o(N)-Tc
int cpm(int n,int dp[]){
    if(n==0) return 1;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=cpm(n-1,dp)+cpm(n-2,dp);
}
//Tabulation
int cpt(int n,int dp[]){
    // dp[n+1];
    // memset(dp,-1,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
void solve(){
    int n;
    cin>>n;
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    cout<<cpt(n,dp)<<endl;
}
    
int main(){
    solve();
return 0;
}