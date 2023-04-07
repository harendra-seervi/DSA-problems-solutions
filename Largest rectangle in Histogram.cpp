#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    stack<int>st;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxi=-999;
    int left[n]; 
    int right[n];
    for(int i=0;i<n;i++){
        while(st.empty()!=true && arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.empty()!=true){
            left[i]=st.top()+1;
            st.push(i);
        }
        else{
            left[i]=0;
            st.push(i);
        }
    }
    while(st.empty()!=true){
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        while(st.empty()!=true && arr[i]<arr[st.top()]){
            st.pop();
        }
        if(st.empty()!=true){
            right[i]=st.top()-1;
            st.push(i);
        }
        else{
            right[i]=n-1;
            st.push(i);
        }
    }
    maxi=-999;
    for(int i=0;i<n;i++){
        int ans=arr[i]*(right[i]-left[i]+1);
        maxi=max(maxi,ans);
    }
    cout<<maxi<<endl;
return 0;
}

//7
//6 2 5 4 5 1 6