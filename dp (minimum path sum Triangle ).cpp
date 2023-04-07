https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp,int n){
    if(i==n-1) return grid[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int d=solve(i+1,j,grid,dp,n)+grid[i][j];
    int dg=solve(i+1,j+1,grid,dp,n)+grid[i][j];
    return dp[i][j]=min(d,dg);
}
int minimumPathSum(vector<vector<int>>& a, int n){
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//     return solve(0,0,triangle,dp,n);
    for(int i=0;i<n;i++){
        dp[n-1][i]=a[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d=a[i][j]+dp[i+1][j];
            int dg=a[i][j]+dp[i+1][j+1];
            dp[i][j]=min(d,dg);
        }
    }
    return dp[0][0];
}