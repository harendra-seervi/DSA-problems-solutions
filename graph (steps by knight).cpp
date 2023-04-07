	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n){
        vector<vector<int>>vis(1002,vector<int>(1002,0));
        int x=KnightPos[0];
        int y=KnightPos[1];
        int xf=TargetPos[0];
        int yf=TargetPos[1];
        if(x==xf && y==yf) return 0;
        queue<pair<int,int>>q;
        q.push({x,y});
        int ct=0;
        while(q.empty()!=true){
            int siz=q.size();
            ct++;
            while(siz--){
                int xc=q.front().first;
                int yc=q.front().second;
                q.pop();
                vis[xc][yc]=1;
                if(xc==xf && yc==yf){
                    return ct;
                }
                if(issafe(xc+1,yc+2,vis,n)){
                    vis[xc+1][yc+2]=1;
                    if(xc+1==xf && yc+2 ==yf){
                        return ct;
                    }
                    q.push({xc+1,yc+2});
                }
                if(issafe(xc+1,yc-2,vis,n)){
                    vis[xc+1][yc-2]=1;
                    if(xc+1==xf && yc-2 ==yf){
                        return ct;
                    }
                    
                    q.push({xc+1,yc-2});
                }
                if(issafe(xc+2,yc-1,vis,n)){
                    vis[xc+2][yc-1]=1;
                    if(xc+2==xf && yc-1 ==yf){
                        return ct;
                    }
                    
                    q.push({xc+2,yc-1});
                }
                if(issafe(xc+2,yc+1,vis,n)){
                    vis[xc+2][yc+1]=1;
                    if(xc+2==xf && yc+1 ==yf){
                        return ct;
                    }
                    
                    q.push({xc+2,yc+1});
                }
                if(issafe(xc-1,yc+2,vis,n)){
                    vis[xc-1][yc+2]=1;
                    if(xc-1==xf && yc+2 ==yf){
                        return ct;
                    }
                    
                    q.push({xc-1,yc+2});
                }
                if(issafe(xc-1,yc-2,vis,n)){
                    vis[xc-1][yc-2]=1;
                    if(xc-1==xf && yc-2 ==yf){
                        return ct;
                    }
                    
                    q.push({xc-1,yc-2});
                }
                if(issafe(xc-2,yc-1,vis,n)){
                    vis[xc-2][yc-1]=1;
                    if(xc-2==xf && yc-1 ==yf){
                        return ct;
                    }
                    
                    q.push({xc-2,yc-1});
                }
                if(issafe(xc-2,yc+1,vis,n)){
                    vis[xc-2][yc+1]=1;
                    if(xc-2==xf && yc+1 ==yf){
                        return ct;
                    }
                    
                    q.push({xc-2,yc+1});
                }
            }
        }
        return -1;
	}