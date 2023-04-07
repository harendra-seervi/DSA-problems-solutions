#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod  1000000007
void solve(){
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(ll i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int i=0;
    int j=1;
    while(j<n && i<j){
        if(arr[j]-arr[i]>k && i+1==j){
            i++;j++;
        }
        else if(arr[j]-arr[i]>k) i++;
        else if(arr[j]-arr[i]<k) j++;
        else{
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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