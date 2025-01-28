//Question: Take a singly linked list as input, then take q queries. In each query you will be given an index and value. You need to insert those values in the given index and print the linked list. If the index is invalid print “Invalid”
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node * next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void insert_at_tail(Node * &head,Node * &tail,int val){
    Node *tmp=new Node(val);
    if(tail==NULL){
        head=tmp;
        tail=tmp;
        return;
    }
    tail->next=tmp;
    tail=tmp;
}
void insert_at_any(Node * &head,int pos,int val){
    Node *newnode=new Node(val);
    Node *tmp=head;
    if(pos==0){
        newnode->next=head;
        head=newnode;
        return;
    }
    for(int i=1;i<pos;i++){
        tmp=tmp->next;
    }
    newnode->next=tmp->next;
    tmp->next=newnode;

}

int main(){
    Node * head=NULL;
    Node * tail=NULL;
    int c=0;
   while(true){
    int x;
    cin>>x;
    if(x==-1){
        break;
    }
    c++;
    insert_at_tail(head,tail,x);
   }
   int p,v;
   //cin>>p>>v;
   
   if(p>(c)){
    cout<<"invalid"<<endl;
    return 0;
   }
   else if(p==(c)){
    insert_at_tail(head,tail,v);
   }
   else{
    insert_at_any(head,p,v);
   }
   Node *t=head;
   while(t!=NULL){
    cout<<t->val<<" ";
    t=t->next;
   }
    return 0;
}
