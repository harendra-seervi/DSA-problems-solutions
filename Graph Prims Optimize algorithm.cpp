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

// 5 6
// 0 1 2 
// 0 3 6
// 3 1 8
// 1 2 3 
// 1 4 5 
// 2 4 7

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>arr[n];
    for(int i=0;i<m;i++){
        int v,u,w;cin>>v>>u>>w;
        arr[v].push_back({u,w});
        arr[u].push_back({v,w});
    }
    int key[n];
    int parent[n];
    bool mst[n];
    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }
    key[0]=0;
    parent[0]=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    for(int j=0;j<n-1;j++){
        int node=pq.top().second;
        pq.pop();
        mst[node]=true;
        for(auto val:arr[node]){
            if(val.second<key[val.first] && mst[val.first]==false){
                key[val.first]=val.second;
                pq.push({val.second,val.first});
                parent[val.first]=node;
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" -> "<<i<<endl;
    }
}
    
int main(){
    solve();
    return 0;
}