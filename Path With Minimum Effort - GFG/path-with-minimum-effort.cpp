//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int drow[4] = {0,0,-1,1};
        int dcol[4] = {1,-1,0,0};
        
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int height = front.first;
            int row = front.second.first;
            int col = front.second.second;
            
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
    
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && max(height,abs(heights[row][col]-heights[nrow][ncol])) < dist[nrow][ncol]){
                    dist[nrow][ncol] = max(height,abs(heights[nrow][ncol] - heights[row][col]));
                    pq.push({max(height,abs(heights[nrow][ncol] - heights[row][col])),{nrow,ncol}});
                }
                
            }
        }
        
        return dist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends