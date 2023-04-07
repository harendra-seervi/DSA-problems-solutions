int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i<0 || j<0|| grid[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int left=solve(i-1,j,grid,dp);
    int up=solve(i,j-1,grid,dp);
    return dp[i][j]=(left+up)%1000000007;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return solve(n-1,m-1,mat,dp);
}