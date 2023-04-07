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
    }
    vector<int>ind(n,0);
    for(int i=0;i<n;i++){
        for(auto val:arr[i]){
            ind[val]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    int ct=0;
    while(q.empty()!=true){
        int n=q.front();
        q.pop();
        ct++;
        for(auto val:arr[n]){
            ind[val]--;
            if(ind[val]==0) q.push(val);
        }
    }
    if(ct==n){
        cout<<"Cycle not present"<<endl;
    }
    else{
        cout<<"Cycle present"<<endl;
    }
}
int main(){
    solve();
    return 0;
}