#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool identical(node*root1,node*root2){
    if(root1==NULL && root2==NULL) return true;
    if((root1==NULL && root2!=NULL) ||(root1!=NULL && root2==NULL)) return false;
    if(root1->data==root2->data && root1!=NULL && root2 !=NULL){
        bool n1=identical(root1->left,root2->left);
        bool n2=identical(root1->right,root2->right);
        if(n1 && n2) return true;
        else return false;
    }
    else{
        return false;
    }
}

int main(){
    node*root1=new node(1);
    root1->left=new node(2);
    root1->right=new node(3);
    root1->left->left=new node(4);
    root1->left->right=new node(5);

    node*root2=new node(1);
    root2->left=new node(2);
    root2->right=new node(3);
    root2->left->left=new node(4);
    root2->left->right=new node(5);
    if(identical(root1,root2)){
        cout<<"identical"<<endl;
    }
    else{
        cout<<"not identical"<<endl;
    }
return 0;
}