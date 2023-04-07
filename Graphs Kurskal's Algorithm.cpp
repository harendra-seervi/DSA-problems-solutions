#include<bits/stdc++.h>
using namespace std;
    
/*
  Think twice before code
*/  

// 6 9
// 1 5 4
// 1 4 1
// 5 4 9
// 4 3 5 
// 4 2 3 
// 1 2 2 
// 3 2 3 
// 3 6 8
// 2 6 7

int parent[10000];
int Rank[10000];
int n;
void makeSet(){
    for(int i=0;i<n;i++){
        parent[i]=i;
        Rank[i]=0;
    }
}
int findPar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findPar(parent[node]);
}

void Union(int u,int v){
    u=findPar(u);
    v=findPar(v);
    if(Rank[u]<Rank[v]){
        parent[u]=v;
    }
    else if(Rank[u]>Rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        Rank[u]++;
    }
}
void solve(){
    cin>>n;
    int m;cin>>m;
    makeSet();
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    int cost=0;
    sort(edges.begin(),edges.end());
    for(auto val:edges){
        if(findPar(val[1])==findPar(val[2])){
            continue;
        }
        else{
            cout<<val[1]<<"->"<<val[2]<<endl;
            Union((val[1]),(val[2]));
            cost+=(val[0]);
        }
    }
    cout<<cost<<endl;
}



int main(){
    solve();
return 0;
}