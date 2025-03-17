//https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution {
    public:
     
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int>dis(V,100000000);
    dis[src]=0;
     for(int i=0;i<(V-1);i++){
         for(auto x:edges){
             int a=x[0];
             int b=x[1];
             int c=x[2];
             if(dis[a]+c<dis[b] && dis[a]!=100000000){
                 dis[b]=dis[a]+c;
             }
         }
     }
     bool cy=false;
     for(auto x:edges){
             int a=x[0];
             int b=x[1];
             int c=x[2];
             if(dis[a]+c<dis[b] && dis[a]!=100000000){
                 cy=true;
                 break;
             }
         }
         if(cy){
             return vector<int>(1, -1);
         }
         else{
             return dis;
         }
      }
  };