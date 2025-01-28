
//Question: Take a singly linked list as input and print the middle element. If there are multiple values in the middle print both.

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
   
  if(c%2==0){
    c=c/2;
    Node * tmp=head;
    for(int i=1;i<c;i++){
     tmp=tmp->next;
    }
    cout<<tmp->val<<" "<<tmp->next->val;
  }
  else{
    c=c/2+1;
    Node * tmp=head;
    for(int i=1;i<c;i++){
     tmp=tmp->next;
    }
    cout<<tmp->val;
  }
    return 0;
}
