#include<bits/stdc++.h>
using namespace std;
int presedance(char ch){
    if(ch=='^') return 3;
    if(ch=='*'|| ch=='/') return 2;
    if(ch=='+'|| ch=='-') return 1;
    else return -1;
}
string infixToPostfix(string s){
    string ans;
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&& s[i]<='z'){
            // st.push(s[i]);
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(st.empty()!=true && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(st.empty()!=true) st.pop();
        }
        else{
            while(st.empty()!=true && (presedance(s[i]))<presedance(st.top())&& st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(st.empty()!=true){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main() {
    string s;
    cin>>s;
    reverse(s.begin(),s.end());

    for(int i=0;i<s.size();i++){
        if(s[i]==')'){
            s[i]='(';
        }
        else if(s[i]=='('){
            s[i]=')';
        }
    }
    cout<<s<<endl;
    string ans=infixToPostfix(s);
    reverse(ans.begin(),ans.end());
    cout<<"Infix to postfix of expression "<<s<<" is "<<ans<<endl;
return 0;
}