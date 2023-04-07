#include<bits/stdc++.h>
using namespace std;
vector <int>v;
void subset(int arr[],int n,int i,string osf){
	if(i==n){
		cout<<osf<<" ";
		int sum=0;
		for(int i=0;i<osf.size();i++){
			sum+=osf[i];
		}
		v.push_back(sum);
		osf.clear();
		return;
	}
	
	subset(arr,n,i+1,osf+to_string(arr[i]));
	subset(arr,n,i+1,osf);
}
int main() {
	int arr[3]={1,2,3};
	subset(arr,3,0,"");
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
return 0;
}