int orangesRotting(vector<vector<int>>& grid) {
        int ct=0;
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j}),vis[i][j]=1,grid[i][j]=0;
            }
        }
        
        while(q.empty()!=true){
            int siz=q.size();
            ct++;
            while(siz--){
                int x=q.front().first;
                int y=q.front().second;
                vis[x][y]=1;
                grid[x][y]=0;
                q.pop();
                //up
                if(issafe(x-1,y,n,m) && grid[x-1][y]==1 && vis[x-1][y]==0){
                    grid[x-1][y]=0;
                    vis[x-1][y]=1;
                    q.push({x-1,y});
                }
                //Down
                if(issafe(x+1,y,n,m) && grid[x+1][y]==1 && vis[x+1][y]==0){
                    grid[x+1][y]=0;
                    vis[x+1][y]=1;
                    q.push({x+1,y});
                }
                if(issafe(x,y+1,n,m) && grid[x][y+1]==1 && vis[x][y+1]==0){
                    grid[x][y+1]=0;
                    vis[x][y+1]=1;
                    q.push({x,y+1});
                }
                if(issafe(x,y-1,n,m) && grid[x][y-1]==1 && vis[x][y-1]==0){
                    grid[x][y-1]=0;
                    vis[x][y-1]=1;
                    q.push({x,y-1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ct-1;
    }