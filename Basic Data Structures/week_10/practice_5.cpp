//Question: Take a doubly linked list as input and sort it in ascending order. Then print the list.
#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
   int val;
   Node *next;
   Node *pre;
   Node(int val){
    this->val=val;
    this->next=NULL;
    this->pre=NULL;
   }
};
void insert_at_tail(Node *&head,Node *&tail,int val){
    Node *newnode=new Node(val);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    newnode->pre=tail;
    tail=newnode;
}

void sort_list(Node *&head){
    for(Node *i=head;i->next!=NULL;i=i->next){
        for(Node *j=i->next;j!=NULL;j=j->next){
            if(i->val>j->val){
                swap(i->val,j->val);
            }
        }
    }
}


int main(){
    Node *head1=NULL;
    Node *tail1=NULL;
    int val;
    while(true){
        cin>>val;
        if(val==-1){
            break;
        }
        
        insert_at_tail(head1,tail1,val);
    }
   sort_list(head1);
    Node *t=head1;
    while(t!=NULL){
     cout<<t->val<<" ";
     t=t->next;
    }

    
    return 0;
}