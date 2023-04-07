#include<iostream>
#include<bits./stdc++.h>
using namespace std;
struct node{
    public:
    node*left;
    node*right;
    int data;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
// {bst , size , min , max}
vector<int> largest(node*root){
    if(root==NULL){
        return  {1,0,INT_MAX,INT_MIN};
    }
    else if(root->left==NULL && root->right==NULL){
        return {1,1,root->data,root->data};
    }
    vector<int> l=largest(root->left);
    vector<int> r=largest(root->right);
    if(l[0]==1 && r[0]==1 && root->data>l[0] && root->data<r[0]) return {1,l[1]+r[1]+1,min(root->data,min(l[2],r[2])),max(root->data,max(l[3],r[3]))};
    return {0,l[1]+r[1],min(root->data,min(l[2],r[2])),max(root->data,max(l[3],r[3]))};
}
int main(){
    node*root=new node(8);
    root->left=new node(7);
    root->right=new node(12);
    root->left->left=new node(5);
    root->left->right=new node(10);
    root->left->left->left=new node(2);
    root->left->left->right=new node(6);
    root->right->right=new node(9);
    root->right->right->right=new node(10);
    root->right->left=new node(2);
    vector<int>ans=largest(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}