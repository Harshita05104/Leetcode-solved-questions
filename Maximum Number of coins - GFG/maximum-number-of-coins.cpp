//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int rec(vector<int> &a,int l,int r,vector<vector<int>> &dp){
            if(l>r) return 0;
            if(dp[l][r]!=-1) return dp[l][r];
            int mx = INT_MIN;
            for(int k=l;k<=r;k++){
                int ans = rec(a,l,k-1,dp) + rec(a,k+1,r,dp) + a[k]*a[l-1]*a[r+1];
                mx = max(mx,ans);
            }
            return dp[l][r] = mx;
        }
        int maxCoins(int N, vector <int> &a)
        {
                a.push_back(1);
                a.insert(a.begin(),1);
                vector<vector<int>> dp(N+5,vector<int>(N+5,-1));
                return rec(a,1,N,dp);
                
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends