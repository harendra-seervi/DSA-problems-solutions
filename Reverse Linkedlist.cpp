#include<bits./stdc++.h>
using namespace std;

//    construction of node
class node{
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }
};

//  insert at tail

void insertattail(node *&head,int val){
    node *temp=head;
    node *n=new node(val);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

// display

void display(node *&head){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
}
//  reverselinkedlist

void reverselinkedlist(node *&head){
    node *previous=NULL;
    node *current=head;
    node *next=current->next;
    while(next!=NULL){
        current->next   =previous;   //+
        previous=current;                 
        current=next;
        next=next->next;
    }
    current->next=previous;
    head=current;
}
// reverserecursivly

node* reverserecursivly(node *&head ){
    if(head==NULL||head->next==NULL) return head;
   node *newhead=reverserecursivly(head->next);
   head ->next->next=head;
   head->next=NULL;
   return newhead;
}
int main(){
    node *n=new node(1);
    node *head=n;
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    node *newhead=reverserecursivly(head);
    display(newhead);
    return 0;
}
