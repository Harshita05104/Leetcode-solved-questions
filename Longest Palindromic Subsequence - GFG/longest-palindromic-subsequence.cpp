//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestSequence(string a,string b,int i,int j,vector<vector<int>> &dp){
        if(i==a.size()) return 0;
        if(j==b.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        
        if(a[i]==b[j]){
            ans = 1+longestSequence(a,b,i+1,j+1,dp);
        }
        else{
            ans = max(longestSequence(a,b,i,j+1,dp),longestSequence(a,b,i+1,j,dp));
        }
        
        return dp[i][j] = ans;
    }
    int longestPalinSubseq(string A) {
        string a = A;
        reverse(A.begin(),A.end());
        vector<vector<int>> dp(A.length(),vector<int>(A.length(),-1));
        return longestSequence(a,A,0,0,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends