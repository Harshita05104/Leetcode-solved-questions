//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i=0;
        int j=0;
        while(i<S.size() && j<T.size()){
            if(T[j]>='0' && T[j]<='9'){
                int temp = T[j] - '0';
                j++;
                while(j<T.size() && T[j]>='0' && T[j]<='9'){
                    temp*=10;
                    temp+=T[j]-'0';
                    j++;
                }
                i+=temp;
            }
            else{
                if(S[i]==T[j]){
                    i++;
                    j++;
                }
                else{
                    return 0;
                }
            }
        }
        if(i!=S.length()) return 0;
        
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends