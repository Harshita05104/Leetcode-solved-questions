//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        int start = 0;
        int end = S.size()-1;
        vector<int> freq(26,0);
        for(int i=0;i<S.size();i++){
            freq[S[i]-'a']++;
        }
        bool flag = true;
        while(start<end){
            if(flag==true){
                if(freq[S[start]-'a']>1){
                    freq[S[start]-'a']--;
                    S[start] = '#';
                    flag = false;
                }
                start++;
                
            }
            else{
                if(freq[S[end]-'a']>1){
                    freq[S[end]-'a']--;
                    S[end] = '#';
                    flag = true;
                }
                end--;
            }
        }
        string ans = "";
        for(int i=0;i<S.size();i++){
            if(S[i]!='#'){
                ans = ans + S[i];
            }
        }
        
        if(flag==false){
            reverse(ans.begin(),ans.end());
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends