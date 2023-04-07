#include<bits/stdc++.h>
using namespace std;
	
// Tip to avoid bugs.
/*
  *Think twice before code
*/
	
void solve(){
	int n;
	cin>>n;int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int l=0,hi=n-1;
	int key;
	cin>>key;
	while(l<hi){
		int mid=(l+hi)/2;
		if(arr[mid]==key){
			cout<<"found"<<endl;
			return;
			break;
		}
		else if(arr[mid]>key){
			hi=mid-1;
		}
		else if(arr[mid]<key){
			l=mid+1;
		}
	}
	cout<<"Not found"<<endl;
}
	
int main(){
	solve();
return 0;
}