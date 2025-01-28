#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int>q;
    stack<int>s;
    int nq,ns;
    cin>>nq;
    for(int i=0;i<nq;i++){
        int x;
        cin>>x;
        q.push(x);
    }
     cin>>ns;
    for(int i=0;i<ns;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    if(nq!=ns){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<nq;i++){
        int vs,vq;
        vq=q.front();
        vs=s.top();
        if(vs!=vq){
         cout<<"NO"<<endl;
         return 0;
        }
    }
    cout<<"YES"<<endl;

    return 0;
}