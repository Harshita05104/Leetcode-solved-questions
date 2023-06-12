//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int price[],int n,int ind,vector<vector<int>>&dp){
      if(ind==0){
          return dp[ind][n]= n*price[0];
      }
      if(dp[ind][n]!=-1) return dp[ind][n];
      int notTake = solve(price,n,ind-1,dp);
      int take = INT_MIN;
      
      int rodlength = ind+1;
      if(rodlength<=n){
          take = price[ind]+solve(price,n-rodlength,ind,dp);
      }
      
      return dp[ind][n]=max(take,notTake);
  }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(price,n,n-1,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends