//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            string ans = "";
            string temp = "";
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]>='0' && s[i]<='9'){
                    temp=s[i] + temp;
                }
                else{
                    ans+=temp;
                    temp="";
                    ans+=s[i];
                }
            }
            ans+=temp;
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends