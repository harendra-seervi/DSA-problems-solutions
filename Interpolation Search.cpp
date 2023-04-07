#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int key;
    cin>>key;
    int lo=0;
    int hi=n-1;
    bool check=false;
    while(lo<=hi){
        int pos=lo+(((key- arr[lo])/(arr[hi]-arr[lo]) )* (hi-lo));
        if(arr[pos]==key){
            cout<<"value is found at indux "<<pos<<endl;
            check=true;
            break;
        }
        else if(arr[pos]>key){
            hi=pos-1;
        }
        else if(arr[pos]<key){
            lo=pos+1;
        }
    }
    if(check==false) cout<<"value is not found"<<endl;
}
    
int main(){
    solve();
return 0;
}