#include<bits/stdc++.h>
using namespace std;
int main(){
    
    
    stack<int>s;
    int ns;
    cin>>ns;
    for(int i=0;i<ns;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    stack<int>s2;
    for(int i=0;i<ns;i++){
        int v=s.top();
        s.pop();
        s2.push(v);

    }
    for(int i=0;i<ns;i++){
        int v=s2.top();
        s2.pop();
       cout<<v<<" ";

    }
    cout<<endl;
    
    
    return 0;
}