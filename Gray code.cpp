// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void gc(int arr[],int i,int n,vector<string>&v){
        if(i==n){
            string s;
            for(int i=0;i<n;i++){
                s+=to_string(arr[i]);
            }
            v.push_back(s);
            return ;
        }
        gc(arr,i+1,n,v);
        arr[i]=1;
        gc(arr,i+1,n,v);
        arr[i]=0;
    }                                                                                               
    vector<string> graycode(int n)
    {
        int arr[n]={0};
        vector<string>v;
        gc(arr,0,n,v);
        sort(v.begin(),v.end());
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}



  // } Driver Code Ends