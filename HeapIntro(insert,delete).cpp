#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void heapify(int a[],int n,int i){
    int largest=i;
    int l=(2*i);
    int r=(2*i)+1;
    if(l<=n && a[l]>a[largest]){
        largest=l;
    }
    if(r<=n && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(a,largest,i);
        heapify(a,n,largest);
    }
    else return;
}

void deleteNode(int arr[],int &n){
    arr[1]=arr[n];
    n--;
    int i=1;
    while(i<n){
        int left=arr[i*2];
        int right=arr[i*2 +1];
        if(i*2< n){
            if(left>arr[i]){
                swap(arr,i,i*2);
                i=i*2;
            }
        }
        if(i*2 +1 <n){
            if(right>arr[i]){
                swap(arr,i*2+1,i);
                i=i*2+1;
            }
        }
        else{
            return;
        }
    }
}

void insert(int arr[],int &n,int val){
    n++;
    if(n==1){
        arr[n]=val;
        return;
    }
    int i=n;
    arr[i]=val;
    while(i>1){
        int parent=(i/2);
        if(arr[parent]<arr[i]){
            swap(arr,parent,i);
            i=parent;
        }
        else{
            return;
        }
    }
}
void build_heap(int arr[],int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

void heap_sort(int arr[],int n){
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
    heap_sort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}
// int main(){
//     int N=20;
//     int arr[N];
//     int n=0;
//     int siz;
//     cin>>siz;
//     for(int i=1;i<=siz;i++){
//         int val;
//         cin>>val;
//         insert(arr,n,val);
//     }
//     cout<<"Elements before deleting "<<endl;
//     for(int i=1;i<=n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     cout<<"Elements after deleting "<<endl;
//     deleteNode(arr,n);
//     for(int i=1;i<=n;i++){
//         cout<<arr[i]<<" ";
//     }
// return 0;
// }


//8
// 50 30 40 10 5 20 30 60