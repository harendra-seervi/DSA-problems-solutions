#include<bits/stdc++.h>
int fun(int n,vector<vector<int>>&points,vector<vector<int>>&dp,int last){
    if(n==0){
        int maxi=INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[n][i]);
            }
        }
        return maxi;
    }
    if(dp[n][last]!=-1) return dp[n][last];
    int maxi=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point=points[n][i]+fun(n-1,points,dp,i);
            maxi=max(maxi,point);
        }
    }
    return dp[n][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>>dp(n+1,vector<int>(3+1,-1));
    return fun(n-1,points,dp,3);
}