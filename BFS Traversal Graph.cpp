#include<bits/stdc++.h>
using namespace std;
vector<int>bfs(vector<int>arr[],int n,int m){
    vector<int>vis(n,0);
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            queue<int>q;
            q.push(i);
            vis[i]=1;
            while(q.empty()!=true){
                int n=q.front();
                q.pop();
                ans.push_back(n);
                for(auto val:arr[n]){
                    if(!vis[val]){
                        q.push(val);
                        vis[val]=1;
                    }
                }
            }
        }
    }
    return ans;
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
    ans=bfs(arr,n,m);
    return 0;
}