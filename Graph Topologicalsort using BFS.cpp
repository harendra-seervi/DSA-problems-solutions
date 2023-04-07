#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod  1000000007
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>arr[n+1];
    for(int i=0;i<m;i++){
        int v,u;cin>>v>>u;
        arr[v].push_back(u);
    }
    int deg[n];
    memset(deg,0,sizeof(deg));
    for(int i=0;i<n;i++){
        for(auto val:arr[i]){
            deg[val]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(deg[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(q.empty()!=true){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto val:arr[node]){
            deg[val]--;
            if(deg[val]==0){
                q.push(val);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<topo[i]<<" ";
    }
}

    
int main(){
    solve();
    return 0;
}