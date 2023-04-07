#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod  1000000007
    
// tips to avoid bugs.
/*
  * be careful while taking size of array.
  * dont use same variable name.
  * dont get stuck on one idea.
  * verify once before submiting.
*/

// Memoization
int fun(int n,vector<int>&dis,vector<int>&dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int l=fun(n-1,dis,dp)+abs(dis[n]-dis[n-1]);
    int r=INT_MAX;
    if(n>1) r=fun(n-2,dis,dp)+abs(dis[n-2]-dis[n]);
    return dp[n]=min(l,r);
}
// k Jumps Memoization
int fun2(int n ,vector<int>&dis,vector<int>&dp,int k){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int r=INT_MAX;
    for(int i=1;i<=k;i++){
        if(i>1){
            int temp=(fun2(n-i,dis,dp,k)+abs(dis[n-i]-dis[n]));
            r=min(r,temp);
        }
    }
    return dp[n]=r;
}
void solve(){
    int n;
    cin>>n;
    int k;cin>>k;
    vector<int>dis(n);
    vector<int>dp(n,-1);
    for(int i=0;i<n;i++) cin>>dis[i];
    // 1,2 jumps Tabulation
    // dp[0]=0;
    // for(int i=1;i<n;i++){
    //     int l=dp[i-1]+abs(dis[i]-dis[i-1]);
    //     int r=INT_MAX;
    //     if(i>1) r=dp[i-2]+abs(dis[i]-dis[i-2]);
    //     dp[i]=min(r,l);
    // }
    // cout<<dp[n-1]<<endl;
    cout<<fun2(n-1,dis,dp,k)<<endl;
}
    
int main(){
    ll t;
    cin>>t;
    while(t>0){
        solve();
    t--;
    }
    return 0;
}