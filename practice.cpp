#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod  1000000007
  
// tips to avoid bugs.
/*
  * be careful while taking size of array and size of 2D,3D dp.
  * dont use same variable name.
  * dont get stuck on one idea.
  * verify once before submiting.
*/
  
void solve(){
  ll n;
  cin>>n;
  n--;
  ll arr[n];
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<ll>v(n+1,0);
  v[0]=arr[0];
  for(ll i=1;i<=n;i++){
    v[i]=arr[i-1];
  }
  for(ll i=0;i<n;i++){
    if(max(v[i],v[i+1])!=arr[i]){
      if(v[i]==max(v[i],v[i+1])){
        v[i]=arr[i];
      }
      else{
        v[i+1]=arr[i];
      }
    }
  }
  for(ll i=0;i<=n;i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
  
int main(){
  ll t;
  cin>>t;
  while(t>0){
    solve();
  t--;
  }
  return 0;
}