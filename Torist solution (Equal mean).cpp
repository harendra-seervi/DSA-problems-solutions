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
    ll n;
    cin>>n;
    ll arr[n];
    ll sum=0;
    unordered_map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        sum+=(arr[i]);
        mp[arr[i]]++;
    }
    __int128 goal8 = __int128(sum) * (n - 2);
    if(goal8%n==0){
        ll ct=0;
        ll r=sum-(goal8/n);
        for(ll i=0;i<n;i++){
            if(mp[r-arr[i]]){
                if(r-arr[i]!=arr[i]){
                    ct+=(mp[r-arr[i]]);
                }
                else{
                    ct+=(mp[r-arr[i]]-1);
                }
            }
        }
        cout<<ct/2<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
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