#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string l=to_string(arr[i]);
            string r=to_string(arr[j]);
            string ll=l+r;;
            string rr=r+l;
            int fl=stoi(ll);
            int fr=stoi(rr);
            if(fr>fl){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
return 0;
}