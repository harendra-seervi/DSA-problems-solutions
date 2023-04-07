#include<bits/stdc++.h>
using namespace std;
    
bool bfs(vector<int>arr[],vector<int>&vis,int i){
    vis[i]=1;
    queue<pair<int,int>>q;
    q.push({i,-1});
    while(q.empty()!=true){
        int n=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto val:arr[n]){
            if(!vis[val]){
                vis[val]=1;
                q.push({val,n});
            }
            else if(val!=par) return true;
        }
    }
    return false;
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>arr[n+1];
    for(int i=1;i<=m;i++){
        int v,u;
        cin>>v>>u;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }
    vector<int>vis(n+1,0);
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(bfs(arr,vis,i)){
                cout<<"Yes"<<endl;
                return ;
            }
        }
    }
    cout<<"No"<<endl;
}
    
int main(){
    solve();
return 0;
}