//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<vector<pair<int,int>>> adj(N);
         
         for(int i=0;i<edges.size();i++){
             adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
         }
        vector<int> dist(N,INT_MAX);
        dist[0] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int dis = top.first;
            int node = top.second;
            
            for(auto neigh:adj[node]){
                int node2 = neigh.first;
                int wt = neigh.second;
                
                if(dis+wt<dist[node2]){
                    dist[node2] = dis+wt;
                    pq.push({dist[node2],node2});
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX) dist[i] = -1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends