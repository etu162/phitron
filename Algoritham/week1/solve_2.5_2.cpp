#include<bits/stdc++.h>
using namespace std;
 vector<int>adj_list[1005];
 bool  vis[1005];
 int pa[1005];
 int level[1005];
 void bfs(int src){
   queue<int>q;
   q.push(src);
   level[src]=0;
   vis[src]=true;
   while(!q.empty()){
    int par=q.front();
    q.pop();
     
     for(int child:adj_list[par]){
        if(vis[child]==false){
            vis[child]=true;
            int x=level[par]+1;
            level[child]=x;
            pa[child]=par;
            q.push(child);
        }
     }
   }

 } 
int main(){
    int n,e,p,src;
    cin>>n>>e;
   
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int nn;
    cin>>nn;
    cout<<adj_list[nn].size();
    return 0;
}