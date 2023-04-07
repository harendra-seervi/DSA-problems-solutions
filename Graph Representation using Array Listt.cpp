#include<bits/stdc++.h>
using namespace std;
    
/*
  Think twice before code
*/
    
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>arr[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for(int i=0;i<=n;i++){
        cout<<i<<" ";
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
    
int main(){
    solve();
return 0;
}