//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> ans;
        for(int i=0;i<N;i++){
            int id=0;
            for(int j=0;j<Dictionary[i].size();j++){
                if(Dictionary[i][j]>='A' && Dictionary[i][j]<='Z'){
                    if(Dictionary[i][j]==Pattern[id]) id++;
                    else break;
                }
                
                if(id==Pattern.size()){
                    ans.push_back(Dictionary[i]);
                    break;
                } 
            }
        }
            
            if(ans.size()==0) ans.push_back("-1");
            
            sort(ans.begin(),ans.end());
            
            return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends