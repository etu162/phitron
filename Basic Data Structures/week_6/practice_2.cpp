//Question: Take a singly linked list as input and check if the linked list contains any duplicate value. 
//You can assume that the maximum value will be 100.
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
void sort_link_list(Node * &head){
for(Node *i=head;i->next!=NULL;i=i->next){
    for(Node *j=i->next;j!=NULL;j=j->next){
        if(i->val<j->val){
            swap(i->val,j->val);
        }
    }
}
}
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

int main(){
    Node * head=NULL;
    Node * tail=NULL;
   while(true){
    int x;
    cin>>x;
    if(x==-1){
        break;
    }
    insert_at_tail(head,tail,x);
   }
   sort_link_list(head);
   int f=0;
   for(Node *i=head;i->next!=NULL;i=i->next){
    if(i->val==i->next->val){
        f=1;
        break;
    }
   }
    if(f==0){
       cout<<"NO"<<endl; 
    }
    else{
       cout<<"YES"<<endl;  
    }
    return 0;
}
