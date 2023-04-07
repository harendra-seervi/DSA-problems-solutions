#include<bits/stdc++.h>
using namespace std;
void generate(string s,int open,int close ,vector<string>&v){
    if(open==0 && close==0){
        v.push_back(s);
        return ;
    }
    if(open>0){
        s.push_back('(');
        generate(s,open-1,close,v);
        s.pop_back();
    }
    if(open<close && close>0){
        s.push_back(')');
        generate(s,open,close-1,v);
        s.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    string s="";
    int open=n; 
    int close=n;
    vector<string>v;
    generate(s,open,close,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
return 0;
}