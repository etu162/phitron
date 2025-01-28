//Question: Take a doubly linked list as input and check if it forms any palindrome or not.
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
    Node *tail1=NULL;
    int val;
    while(true){
        cin>>val;
        if(val==-1){
            break;
        }
        
        insert_at_tail(head1,tail1,val);
    }
    Node *t1=head1;
    Node *t2=tail1;
    while(t1!=t2 && t1->pre!=t2){
        if(t1->val!=t2->val){
            cout<<"NO"<<endl;
            return 0;
        }
        t1=t1->next;
        t2=t2->pre;
    }
    cout<<"YES"<<endl;
    return 0;
}