//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        long long sum = 0;
        vector<long long> arr(N);
        for(int i=0;i<K;i++){
            arr[i] = GeekNum[i];
            sum+=GeekNum[i];
        }
        int j=0;
        for(int i=K;i<N;i++){
            arr[i] = sum;
            sum = 2*sum - arr[j++];
        }
        return arr[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends