//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPossible(int n,int arr[],int sum1,int sum2,vector<vector<int>> &dp){
        if(sum1==sum2) return true;
        if(sum1<sum2 || n==0) return false;
        
        if(dp[n][sum1]!=-1) return dp[n][sum1];
        
        return dp[n][sum1] = isPossible(n-1,arr,sum1-arr[n-1],sum2+arr[n-1],dp)|| isPossible(n-1,arr,sum1,sum2,dp);
        
    }
    int equalPartition(int n, int arr[])
    {
        int sum1=0;
        int sum2 = 0;
        for(int i=0;i<n;i++){
            sum1+=arr[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(sum1+1,-1));
        return isPossible(n,arr,sum1,sum2,dp); 
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends