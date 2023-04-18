//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    private:
         void generPar(int n, string str, vector<string> & ans,int open , int close){
        if(open==n && close==n){
            ans.push_back(str);
        }
        if(open<n){
            generPar(n,str+'(',ans,open+1,close);
        }
        if(close<open){
            generPar(n,str+')',ans,open,close+1);
        }
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        string str = "";
        generPar(n,"",ans,0,0);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends