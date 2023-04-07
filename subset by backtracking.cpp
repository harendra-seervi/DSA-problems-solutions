#include<bits/stdc++.h>
using namespace std;
void subset(int *arr,vector<int>v,int i,int n){
    if(i==n){

        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
        cout<<endl;
        return ;
    }

    v.push_back(arr[i]);
    subset(arr,v,i+1,n);
    v.pop_back();
    subset(arr,v,i+1,n);
}
int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>v;
    subset(arr,v,0,n);
return 0;
}