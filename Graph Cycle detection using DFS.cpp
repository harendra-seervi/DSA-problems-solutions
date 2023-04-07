#include<bits/stdc++.h>
using namespace std;
    
bool dfs(vector<int>arr[],vector<int>&vis,int i,int par){
    vis[i]=1;
    for(auto val:arr[i]){
        if(!vis[val]){
            vis[val]=1;
            if(dfs(arr,vis,val,i)) return true;
        }
        else if(val!=par) return true;
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
            if(dfs(arr,vis,i,-1)){
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