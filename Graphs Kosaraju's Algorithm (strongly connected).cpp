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
void rdfs(vector<int>arr[],int i,vector<int>&vis){
    vis[i]=1;
    cout<<i<<" ";
    for(auto val:arr[i]){
        if(!vis[val]){
            vis[val]=1;
            rdfs(arr,val,vis);
        }
    }
}
void dfs(vector<int>arr[],int i,vector<int>&vis,stack<int>&st){
    vis[i]=1;
    for(auto val:arr[i]){
        if(!vis[val]){
            vis[val]=1;
            dfs(arr,val,vis,st);
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
    }
    vector<int>vis(n+1,0);
    stack<int>st;
    //step-I
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(arr,i,vis,st);
        }
    }
    //step-II
    vector<int>temp[n+1];
    for(int i=1;i<=n;i++){
        for(auto val:arr[i]){
            temp[val].push_back(i);
        }
    }
    //step-III
    for(int i=1;i<=n;i++)vis[i]=0;
    while(st.empty()!=true){
        if(!vis[st.top()]){
            cout<<"SCC"<<endl;
            rdfs(temp,st.top(),vis);
            cout<<endl;
        }
        st.pop();
    }
}
int main(){
    solve();
    return 0;
}