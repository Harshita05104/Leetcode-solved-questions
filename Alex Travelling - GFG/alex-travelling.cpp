//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        //creating an adjacency list
        vector<vector<vector<int>>> adj(n+1);
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            
            adj[u].push_back({v,w});
        }
        
        //initialising an array 
        vector<int> dis(n+1,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[k] = 0;
        pq.push({0,k});
        
        while(pq.size()>0){
            auto front = pq.top();
            pq.pop();
            int dist = front.first;
            int node = front.second;
            
            //Go through the neighbours of front
            for(auto neigh: adj[node]){
                if(neigh[1] + dist < dis[neigh[0]]){
                    dis[neigh[0]] = neigh[1] + dist;
                    pq.push({dis[neigh[0]],neigh[0]});
                }
            }
        }
        
        //finding the max of dis array
        int ans = INT_MIN;
        for(int i = 1;i<=n;i++){
            if(dis[i]==INT_MAX){
                return -1;
            }
            if(dis[i]>ans){
                ans = dis[i];
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends