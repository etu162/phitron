#include<bits/stdc++.h>
using namespace std;
 vector<int>adj_list[100005];
 bool  vis[100005];
 void dfs(int src){
   vis[src]=true;
   for(auto child:adj_list[src]){
    if(!vis[child]){
        dfs(child);
    }
   }

 } 
int main(){
    int n,e,dst,src;
    cin>>n>>e;
    vector<int>v;
   int c;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            v.push_back(i);
            dfs(i);
        }
    }
    
    c=v.size();
    cout<<c-1<<endl;
    for(int i=1;i<v.size();i++){
        
        cout<<v[i-1]<<" "<<v[i]<<endl;
    }
    
    return 0;
}