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
    vector<int>arr[n+1];
    for(int i=0;i<m;i++){
        int v,u;cin>>v>>u;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }
    vector<int>dis(n,INT_MAX);
    queue<int>q;
    q.push(0);
    dis[0]=0;
    for(int i=0;i<n;i++){
        int n=q.front();
        q.pop();
        for(auto val: arr[n]){
            if(dis[n]+1<dis[val]){
                dis[val]=dis[n]+1;
                q.push(val);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dis[i]<<endl;
    }
}   
    
int main(){
    solve();
    return 0;
}