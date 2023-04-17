//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    vector<int> indegree(n,0);
	    vector<vector<int>> adj(n);
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	    }
	    for(int i=0;i<prerequisites.size();i++){
	        indegree[prerequisites[i].first]++;
	    }
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    int count = 0;
	    
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        count++;
	        for(auto ng:adj[front]){
	            indegree[ng]--;
	            if(indegree[ng]==0){
	                q.push(ng);
	            }
	        }
	    }
	    
	    if(count==n) return true;
	    
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends