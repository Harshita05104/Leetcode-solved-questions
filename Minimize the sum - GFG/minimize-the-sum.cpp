//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        int ans = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0;i<N;i++){
            pq.push(arr[i]);
        }
        if(pq.size()==1) return 0;
        while(!pq.empty()){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans+=a+b;
            pq.push(a+b);
            if(pq.size()==1) break;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends