#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    int transform (string A, string B){
        int N = A.size();
        int M = B.size();
        int hash1[256] = {0};int hash2[256] = {0};
        if(N != M) return -1;
        for(int i = 0; i < N; i++) hash1[A[i]]++;
        for(int i = 0; i < M; i++) hash2[B[i]]++;
        for(int i = 0; i < 256; i++) if(hash1[i] != hash2[i]) return -1;
       int i = N-1;
       int j = M-1;
       cout<<A<<endl;
       cout<<B<<endl;
        while(i>=0 && j>=0)
        {
            if(A[i] == B[j]) 
                { 
                    i--;
                    j--;
                }
            else i--;   
        }
        cout<<A[i]<<endl;
        cout<<B[j]<<endl;
        return j+1;
    }
};
int main () 
{
    int t; cin >> t;
    while (t--){
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}