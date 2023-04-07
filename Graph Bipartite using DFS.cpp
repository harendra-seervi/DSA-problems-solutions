#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod  1000000007

bool dfs(vector<int>arr[],int col[],int i){
    col[i]=1;
    for(auto val: arr[i]){
        if(col[val]==-1){
            col[val]=1-col[i];
            if(dfs(arr,col,val)) return true;
        }
        else if(col[val]==col[i]) return false;
    }
    return false;
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
    int col[n];
    memset(col,-1,sizeof(col));
    for(int i=0;i<n;i++){
        if(col[i]==-1){
            if(!dfs(arr,col,i)){
                cout<<"Not"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

    
int main(){
    solve();
    return 0;
}