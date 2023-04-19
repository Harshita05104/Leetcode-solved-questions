//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        string ans = "";
        int range = 0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='1'){
                ans.push_back('1');
                range = X;
            }
            else if(S[i]=='0' && range>0){
                ans.push_back('1');
                range--;
            }
            else{
                ans.push_back('0');
            }
        }
        range = 0;
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]=='1'){
                range = X;
            }
            else if(S[i]=='0' && range>0){
                ans[i] = '1';
                range--;
            }
        }
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='0'){
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends