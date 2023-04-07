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
int generateper(int num,bool isodd){
    int sum=num;
    if(isodd==1){
        num=num/10;
    }
    while(num>0){
        sum=((sum*10)+(num%10));
        num=num/10;
    }
    return sum;
}
void solve(){
    int n;
    cin>>n;
    int num=-1;
    for(int j=0;j<2;j++){
        int i=1;
        while((num=generateper(i,j))<=n){
            cout<<num<<" "<<endl;
            i++;
        }
        num=-1;
    }
}
    
int main(){
    solve();
    return 0;
}