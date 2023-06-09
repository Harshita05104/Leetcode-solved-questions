//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void permute(set<string>& ans,string S,int ind,int n){
	        if(ind==n) ans.insert(S);           
	        
	        for(int i=ind;i<n;i++){
    	       swap(S[i],S[ind]);
    	       permute(ans,S,ind+1,n);
    	       swap(S[i],S[ind]);
	            
	        }
	        
	        
	    }
		vector<string> find_permutation(string S)
		{
		    int n = S.size();
		    set<string> ans;
		    permute(ans,S,0,n);
		    vector<string> res;
		    for(auto i:ans){
		        res.push_back(i);
		    }
		    sort(res.begin(),res.end());
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends