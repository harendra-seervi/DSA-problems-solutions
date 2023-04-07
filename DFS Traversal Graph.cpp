#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>&vis,vector<int>arr[],vector<int>&ans){
    ans.push_back(node);
    vis[node]=1;
    for(auto val: arr[node]){
        if(!vis[val]){
            vis[val]=1;
            dfs(val,vis,arr,ans);
        }
    }
}
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
    vector<int>ans;
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,vis,arr,ans);
        }
    }
    cout<<"DFS of given tree is"<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}