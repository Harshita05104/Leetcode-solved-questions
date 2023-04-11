//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    vector<vector<int>> dis(n+1,vector<int>(n+1,INT_MAX));
	     int drow[8] = {-2,-2,-1,-1,1,1,2,2};
	     int dcol[8] = {1,-1,2,-2,2,-2,1,-1};
	     if(KnightPos[0]==TargetPos[0] && KnightPos[1] == TargetPos[1]){
	         return 0;
	     }
	     
	     queue<pair<pair<int,int>,int>> q;
	     q.push({{KnightPos[0],KnightPos[1]},0});
	     dis[KnightPos[0]][KnightPos[1]] = 0;
	     
	     while(!q.empty()){
	         auto front = q.front();
	         q.pop();
	         int row = front.first.first;
	         int col = front.first.second;
	         int steps = front.second;
	         
	         for(int i=0;i<8;i++){
	             int nrow = row + drow[i];
	             int ncol = col + dcol[i];
	             
	             if(nrow>=1 && nrow<=n && ncol>=1 && ncol<=n && dis[nrow][ncol]>steps+1){
	                 dis[nrow][ncol] = steps+1;
	                 q.push({{nrow,ncol},steps+1});
	                 if(TargetPos[0]==nrow && TargetPos[1]==ncol){
	                     return steps+1;
	                 }
	             }
	         }
	     }
	     
	     return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends