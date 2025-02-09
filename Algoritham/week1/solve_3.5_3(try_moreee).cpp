#include<bits/stdc++.h>
using namespace std;
bool vis[1005];
int c=0;
vector<int>adj_list[1005];

void dfs(int src){
   c++;
   vis[src]=true;
   for(int child:adj_list[src]){
    if(vis[child]==false){
        dfs(child);
    }
   }
}

int main(){
     int n,e,src;
    cin>>n>>e;
   int ans=0;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<int>v;
   for(int i=0;i<n;i++){
    if(vis[i]==false){
        ans++;
        v.push_back(i);
        dfs(i);
    }
   }
  sort(v.begin(),v.end());
  for(auto x:v){
    cout<<x<<" ";
  }
    return 0;
}