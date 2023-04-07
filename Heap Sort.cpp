#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int i,int j){
    int  temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
//Nlog(N)
void insert(int arr[],int &n,int ele){
    n++;
    if(n==1){
        arr[n]=ele;
        return;
    }
    int i=n;
    arr[n]=ele;
    while(i>1){
        int parent=i/2; //parent element of i
        if(arr[parent]<arr[i]){
            swap(arr,parent,i);
            i=parent;
        }
        else{
            return;
        }
    }
}

void deleteEle(int arr[],int &n){
    if(n<1){
        cout<<"There is no element"<<endl;
        return;
    }
    if(n==1){
        n--;
        return;
    }
    arr[1]=arr[n];
    n--;
    int i=1;
    while(i<=n){
        int l=i*2;
        int r=i*2+1;
        if(l<=n && arr[l]>arr[i]){
            swap(arr,i,l);
            i=l;
        }
        if(r<=n && arr[r]>arr[i]){
            swap(arr,i,r);
            i=r;
        }
        else return;
    }
}

void heapify(int arr[],int n,int i){
    int largest=i;
    int l=i*2;
    int r=i*2+1;
    if(l<=n){
        if(arr[largest]<arr[l]){
            largest=l;
        }
    }
    if(r<=n){
        if(arr[largest]<arr[r]){
            largest=r;
        }
    }
    if(largest!=i){
        swap(arr,largest,i);
        heapify(arr,n,largest);
    }
}

void build_heap(int arr[],int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}
void heapsort(int arr[],int n){
    for(int i=n;i>1;i--){
        swap(arr,i,1);
        heapify(arr,i-1,1);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    build_heap(arr,n);
    cout<<"Build Max heap"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"After heap sort"<<endl;
    heapsort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// int main(){
//     int arr[100];
//     int n=0;
//     for(int i=0;i<8;i++){
//         int val ;
//         cin>>val;
//         insert(arr,n,val);
//     }
//     deleteEle(arr,n);
//     for(int i=1;i<=n;i++){
//         cout<<arr[i]<<" ";
//     }
// return 0;
// }