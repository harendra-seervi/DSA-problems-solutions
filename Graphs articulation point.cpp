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
void dfs(int node,int parent, vector<int> &vis,vector<int> &tin,vector<int> &low,int &timer,vector<int> adj[],vector<int>&isart){
    vis[node]=1;
    tin[node]=low[node]=timer++;
    int child=0;
    for(auto it:adj[node]){
        if(it==parent)continue;
        if(!vis[it]){
            dfs(it,node,vis,tin,low,timer,adj,isart);
            low[node]=min(low[node],low[it]);
            if(low[it]>=tin[node] && parent!=-1){
                isart[node]=1;
            }
            child++;
        }
        else{
            low[node]=min(low[node],tin[it]);
        }
        if(parent==-1 && child>1){
            isart[node]=1;
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>arr[n+1];
    for(int i=0;i<m;i++){
        int v,u;cin>>v>>u;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }
    vector<int>vis(n+1,0);
    vector<int>low(n+1,0);  
    vector<int>tin(n+1,0);
    vector<int>isart(n+1,0);
    int timer=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            // visa [i]=1;
            dfs(i,-1,vis,tin,low,timer,arr,isart);
        }
    }
    for(int i=0;i<isart.size();i++){
        if(isart[i]==1){
            cout<<i<<endl;
        }
    }
    
}
    
int main(){
    solve();
    return 0;
}