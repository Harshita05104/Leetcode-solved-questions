//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&adj,vector<bool>&vis,int i,int &n,int &e){
        vis[i] = true;
        n++;
        e+=adj[i].size();
        
        for(auto ind:adj[i]){
            if(!vis[ind]){
                dfs(adj,vis,ind,n,e);
            }
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        int count = 0;
        int n = 0;
        int e = 0;
        vector<bool> vis(V+1,false);
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                n=0; e=0;
                dfs(adj,vis,i,n,e);
                if(e== n*(n-1)){
                    count++;
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends