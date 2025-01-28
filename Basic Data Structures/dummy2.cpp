#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node * left;
    Node * right;
    int val;
    Node(int val){
     this->left=NULL;
     this->right=NULL;
     this->val=val;
    }
};
void level_order(Node * root){
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        Node * f=q.front();
        q.pop();
        cout<<f->val<<" ";
        if(f->left!=NULL){
            q.push(f->left);
        }
        if(f->right!=NULL){
            q.push(f->right);
        }
    }
}
Node * input(){
    int x;
    cin>>x;
    queue<Node *>q;
    Node *root;
    if(x==-1){
        root=NULL;
    }
    else{
        root=new Node(x);
    }
    q.push(root);
    while(!q.empty()){
        Node *p=q.front();
        q.pop();

        int l,r;
        Node *myright,*myleft;
        cin>>l>>r;
        if(l!=-1){
        myleft=new Node(l);
        }
        else{
            myleft=NULL;
        }
        if(r!=-1){
            myright=new Node(r);
        }
        else{
            myright=NULL;
        }
        p->left=myleft;
        p->right=myright;


        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }
    return root;
}
int main(){

    Node * root=input();
    level_order(root);
    
    return 0;
}