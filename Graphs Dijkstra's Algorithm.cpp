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
    
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>arr[n+1];
    for(int i=0;i<m;i++){
        int v,u,w;cin>>v>>u>>w;
        arr[v].push_back({u,w});
        arr[u].push_back({v,w});
    }
    vector<int>dis(n+1,INT_MAX);
    dis[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    while(pq.empty()!=true){
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        for(auto val:arr[node]){
            if(dis[val.first]==INT_MAX||val.second+d<dis[val.first]){
                dis[val.first]=val.second+d;
                pq.push({dis[val.first],val.first});
            }
        }
    }
    for(int i=0;i<=n;i++){
        cout<<i<<" "<<dis[i]<<endl;
    }
}
    
int main(){
    solve();
    return 0;
}