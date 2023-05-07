//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        string ans = "";
        ans+=str[0];
        for(int i=1;i<str.size();i++){
            if(str[i]<str[i-1]){
                ans +=str[i];
            }
            else if(str[i]==str[i-1]){
                if(ans.size()>1){
                    ans+=str[i];
                }
                else break;
            }
            else break;
        }
        
        string reversed = ans;
        for(int i=reversed.size()-1;i>=0;i--){
            ans+=reversed[i];
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends