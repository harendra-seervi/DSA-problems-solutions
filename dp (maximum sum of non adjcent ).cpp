#include<bits/stdc++.h>
using namespace std;
// memoization
int fun(int n,vector<int>&arr,vector<int>&dp){
    if(n==0) return arr[0];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int tk=fun(n-2,arr,dp)+arr[n];
    int ntk=fun(n-1,arr,dp);
    return dp[n]=max(tk,ntk);
}
// Space Optimization
int maximumNonAdjacentSum(vector<int> &nums){
    int pre2=0;
    int pre=nums[0];
    int curi;
    for(int i=1;i<nums.size();i++){
        curi=max(nums[i]+pre2,pre);
        pre2=pre;
        pre=curi;
    }
    return curi;
}
void solve(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // cout<<fun(n,arr,dp);
    // Tabulation
    dp[0]=arr[0];
    dp[1]=arr[1];
    for(int i=2;i<=n;i++){
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
    }
    // for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
    cout<<dp[n]<<endl;

    // cout<<arr[n]<<endl;
    // cout<<dp[n]<<endl;

}
int main(){
    solve();
return 0;
}