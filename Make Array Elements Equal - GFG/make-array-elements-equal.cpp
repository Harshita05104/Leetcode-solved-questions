//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minOperations(int N) {
        long long int ans = 0;
        long long res;
        if(N%2==0){
            res = N/2;
            //res = res*1LL;
            ans = 1LL*res*res;
        }
        else{
            res = N/2;
            //res = res*1LL;
            ans = 1LL*res*(res+1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}
// } Driver Code Ends