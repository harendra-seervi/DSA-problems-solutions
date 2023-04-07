#include<bits/stdc++.h>
using namespace std;
    
/*
  Think twice before code
*/  

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
    u=parent[u];
    v=parent[v];
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
    makeSet();
    while(n--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    if(findPar(3)!=findPar(2)){
        cout<<"Belongs to different components"<<endl;
    }else{
        cout<<"Belongs to same components"<<endl;
    }
}
    
int main(){
    solve();
return 0;
}