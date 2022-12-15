//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int N) {
        string s = "";
        int divi = N/26;
        for(int i = 0;i<divi;i++){
             s=s+"abcdefghijklmnopqrstuvwxyz";
                 }
        if(N %2==0){
                N = N%26;
                for(int i = 0;i<N/2;i++){
                    char p = 'a'+i;
                    s = s+p;
                }
                for(int i = 26-(N/2);i<26;i++){
                    char p = 'a'+i;
                    s = s+p;
                }
            }
        else{
            int temp = N;
            int sum = 0;
            while(temp!=0){
                sum = sum+(temp%10);
                temp = temp/10;
            }
            if(sum%2==0){
                 N = N%26;
                for(int i = 0;i<(N+1)/2;i++){
                    char p = 'a'+i;
                    s = s+p;
                }
                for(int i = 26-(N-1)/2;i<26;i++){
                    char p = 'a'+i;
                    s = s+p;
                }
            }
            else{
                 N = N%26;
                for(int i = 0;i<(N-1)/2;i++){
                    char p = 'a'+i;
                    s = s+p;
                }
                for(int i = 26-(N+1)/2;i<26;i++){
                    char p = 'a'+i;
                    s = s+p;
                }
                
            }
            
        }
        
        return s;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends