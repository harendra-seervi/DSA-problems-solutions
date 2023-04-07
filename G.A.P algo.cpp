
// time complexity   Nlog(N)
#include<bits./stdc++.h>
using namespace std;

int nextGap(int gap)
{
	if (gap <= 1) return 0;
	return (gap / 2) + (gap % 2);
}
void solve(int arr1[],int arr2[],int n,int m){
    int gap=(n+m);
    int i=0;
    int j=i+gap;
    while(gap!=0 ){
        while(j<n && i<n){
            if(arr1[i]>arr1[j]){
                int temp=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp;
            }
            j++;
            i++;            
        }
        j=0;
        while(j<m && i<n){
            if(arr1[i]>arr2[j]){
                int temp=arr1[i];
                arr1[i]=arr2[j];
                arr2[j]=temp;
            }
            j++;i++;
        }
        i=0;
        while(i<m && j<m){
            if(arr2[i]>arr2[j]){
                int temp=arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=temp;
            }
            j++;i++;
        }
        gap=nextGap(gap);
        i=0;j=i+gap;
    }
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    solve(arr1,arr2,n,m);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
    return 0;
}