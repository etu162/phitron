//Question: Take two doubly linked lists as input and check if they are the same or not.
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
int main(){
    Node *head1=NULL;
    Node *head2=NULL;
    Node *tail1=NULL;
    Node *tail2=NULL;
    int val,l1=0,l2=0;
    while(true){
        cin>>val;
        if(val==-1){
            break;
        }
        l1++;
        insert_at_tail(head1,tail1,val);
    }
      while(true){
        cin>>val;
        if(val==-1){
            break;
        }
        l2++;
        insert_at_tail(head2,tail2,val);
    }
    if(l1!=l2){
        cout<<"NO";
        return 0;
    }
    Node *t1=head1;
    Node *t2=head2;

    while(t1!=NULL){
        cout<<".."<<t1->val<<".."<<t2->val<<endl;
        if(t1->val!=t2->val){
            cout<<"NO"<<endl;
            return 0;
        }
        t1=t1->next;
        t2=t2->next;
    }
    cout<<"YES";


    
    return 0;
}