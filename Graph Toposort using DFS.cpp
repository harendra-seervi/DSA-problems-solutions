#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod  1000000007
void dfs(vector<int>arr[],vector<int>&vis,stack<int>&st,int i){
    vis[i]=1;
    for(auto val: arr[i]){
        if(!vis[i]){
            vis[val]=1;
            dfs(arr,vis,st,val);
        }
    }
    st.push(i);
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
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(arr,vis,st,i);
        }
    }
    while(st.empty()!=true){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    solve();
    return 0;
}