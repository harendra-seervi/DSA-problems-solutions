#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int s;
    cin>>s;
    int sum=0;
    int i;
    for(i=0;i<n;i++){
        int j;
        sum=0;
        for(j=i;j<n;j++){
            sum=sum+array[j];
           if(sum==s){
                cout<<i+1<<" to "<<j+1<<endl;
            }
        }  
    }
return 0;
}