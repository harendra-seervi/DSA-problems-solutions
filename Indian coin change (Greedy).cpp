#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[10];
    arr[0]=2000;
    arr[1]=500;
    arr[2]=200;
    arr[3]=100;
    arr[4]=50;
    arr[5]=20;
    arr[6]=10;
    arr[7]=5;
    arr[8]=2;
    arr[9]=1;
    int x; cin>>x;
    int sum=0;
    int ct=0;
    for(int i=0;i<10;i++){
        while(sum+arr[i]<=x){
            sum+=arr[i];
            ct++;
        }
        if(sum==x) break;
    }
    cout<<ct<<endl;
return 0;
}