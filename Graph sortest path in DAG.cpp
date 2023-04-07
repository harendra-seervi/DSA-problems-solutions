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
void dfs(vector<pair<int,int>>arr[],vector<int>&vis,stack<int>&st,int i){
    vis[i]=1;
    for(auto val:arr[i]){
        if(!vis[val.first]){
            vis[val.first]=1;
            dfs(arr,vis,st,val.first);
        }
    }
    st.push(i);
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>arr[n+1];
    //DAG
    for(int i=0;i<m;i++){
        int v,u,w;cin>>v>>u>>w;
        arr[v].push_back({u,w});
    }
    stack<int>topo;
    vector<int>dis(n,INT_MAX);
    dis[0]=0;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(arr,vis,topo,i);
        }
    }
    while(topo.empty()!=true){
        int x=topo.top();
        topo.pop();
        for(auto val: arr[x]){
            if(dis[val.first]==INT_MAX ||val.second+dis[x]<dis[val.first]){
                dis[val.first]=val.second+dis[x];
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dis[i]<<endl;
    }
}
    
int main(){
    solve();
    return 0;
}