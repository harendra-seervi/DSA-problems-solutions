#include<iostream>
using namespace std;
int divisableby5(int n){
    int count=0;
    for(int i=1;i<=n;i++){
    if(i%5==0){
       count++;
    }
    }
return count;
}
int divisableby7(int n){
    int count=0;
    for(int i=1;i<=n;i++){
    if(i%7==0){
        count++;
     }
    }
return count;
}
int divisableby7and5(int n){
    int count=0;
    for(int i=1;i<=n;i++){
    if((i%7==0)&&(i%5==0)){
        count++;
     }
    }
    return count;
}
int main() {
    int n;
    cin>>n;
    cout<<(divisableby5(n)+divisableby7(n))-divisableby7and5(n);
return 0;
}