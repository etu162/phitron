#include<bits/stdc++.h>
using namespace std;
 vector<int>adj_list[100005];
 bool  vis[100005];
 void dfs(int src){
   vis[src]=true;
   cout<<"src is "<<src<<"..."<<vis[src]<<endl;
   for(auto child:adj_list[src]){
    if(!vis[child]){
        cout<<"enter in flase"<<endl;
        dfs(child);
    }
   }

 } 
int main(){
    int n,e,dst,src;
    cin>>n>>e;
   int c=0;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cout<<i<<"..."<<endl;
            c++;
            dfs(i);
        }
    }
    c=c-1;
    cout<<c-1<<endl;
    
    return 0;
}