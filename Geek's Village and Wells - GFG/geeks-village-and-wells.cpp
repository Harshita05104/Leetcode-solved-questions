//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>> ans(n,vector<int>(m,-1));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='W'){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                if(c[i][j]=='N'){
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                }
                if(c[i][j]=='.'){
                    ans[i][j] = 0;
                }
            }
        }
        
        int drow[] = {0,0,-1,1};
        int dcol[] = {-1,1,0,0};
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int row = front.first.first;
            int col = front.first.second;
            int dist = front.second;
            
            if(c[row][col]=='.'){
                ans[row][col] = 0;
            }
            else{
                ans[row][col] = dist;
            }
            
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    if(c[nrow][ncol]=='N'){
                        ans[nrow][ncol] = 0;
                        vis[nrow][ncol] = 1;
                    }
                    else if(c[nrow][ncol]=='H' || c[nrow][ncol]=='.'){
                        q.push({{nrow,ncol},dist+2});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends