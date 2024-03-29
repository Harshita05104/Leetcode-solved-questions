//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n = grid.size();
        int m = grid[0].size();
        if(source.first==destination.first && source.second==destination.second){
            return 0;
        }
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[source.first][source.second] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first,source.second}});
        int drow[4] = {1,0,0,-1};
        int dcol[4] = {0,1,-1,0};
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int dis = front.first;
            int row = front.second.first;
            int col = front.second.second;
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && 
                (dis + 1)<dist[nrow][ncol]){
                    if(nrow==destination.first && ncol==destination.second){
                        return dis+1;
                    }
                    dist[nrow][ncol] = dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends