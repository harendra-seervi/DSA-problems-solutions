#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr[n+1];
    for(int i=1;i<=m;i++){
        int v,u;
        cin>>v>>u;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }
    vector<int>vis(n+1);
    for(int i=0;i<n+1;i++){
        vis[i]=-1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            vis[i]=1;
            queue<pair<int,int>>q;
            q.push({i,vis[i]});
            while(q.empty()!=true){
                int n=q.front().first;
                int cl=q.front().second;
                q.pop();
                for(auto val:arr[n]){
                    if(vis[val]==-1){
                        vis[val]=1-cl;
                        q.push({val,vis[val]});
                    }
                    else if(vis[val]==cl){
                        cout<<"Not an bipartite graph"<<endl;
                        return 0;
                    }
                }
            }
        }   
    }
    cout<<"It is an bipartite graph"<<endl;
    return 0;
}