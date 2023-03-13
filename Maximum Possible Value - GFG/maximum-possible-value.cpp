//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int n,vector<int> a, vector<int> b) {
        int sum = 0;
        long long ans = 0;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            if(b[i]%2!=0) b[i]-=1;
            sum+=b[i];
            ans = ans + (a[i]*b[i]);
            if(b[i]!=0){
                mini = min(mini,a[i]);
            }
        }
        if(mini==INT_MAX) mini = 0;
        if(sum%4==0) return ans;
        else return ans-(mini*2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends