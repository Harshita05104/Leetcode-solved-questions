//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int func(string &a,string &b,int i,int j,vector<vector<int>> &dp){
	        if(i==a.size()) return 0;
	        if(j==b.size()) return 0;
	        
	        if(dp[i][j]!=-1) return dp[i][j];
	        int ans =0;
	        if(a[i]==b[j] && i!=j){
	            ans = 1+func(a,b,i+1,j+1,dp);
	        }
	        else{
	            ans = max(func(a,b,i,j+1,dp),func(a,b,i+1,j,dp));
	        }
	        return dp[i][j] = ans;
	        
	    }
		int LongestRepeatingSubsequence(string str){
		    vector<vector<int>> dp(str.size()+1,vector<int>(str.size()+1,-1));
		    return func(str,str,0,0,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends