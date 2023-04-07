// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    
    string swap(string &s,int i,int j){
        
        return s;
    }
    //Function to find the largest number after k swaps.
    void solve(string &s,int k,string &maxi){
        if(s>maxi){
            maxi=s;
        }
        if(k==0){
            return;
        }
        for(int i=0;i<s.size()-1;i++){
            for(int j=i+1;j<s.size();j++){
                if(s[j]>s[i]){
                    s=swap(s,i,j);
                    solve(s,k-1,maxi);
                    s=swap(s,i,j); 
                }
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string maxi="-999";
       solve(str,k,maxi);
       return maxi;
       
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends