//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int> balloon(26);
        
        for(int i=0;i<s.size();i++){
            balloon[s[i]-'a']++;
        }
        
        int freq_b = balloon['b'-'a'];
        int freq_a = balloon['a'-'a'];
        int freq_n = balloon['n'-'a'];
        int freq_l = (balloon['l'-'a'])/2;
        int freq_o = (balloon['o'-'a'])/2;
        
        int mini = min({freq_b,freq_a,freq_n,freq_l,freq_o});
        
        return mini;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends