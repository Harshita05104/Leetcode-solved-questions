//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        string ans = "";
        if(D==1 || S==1 || S>=9*D) return "-1";
        S = S-1;
        int dup = S;
        for(int i=0;i<D-1;i++){
            if(S>=9){
                S-=9;
                ans = "9" + ans;
            }
            else{
                ans = to_string(S) + ans;
                S = 0;
            }
        }
        if(S==0) ans = "1" + ans;
        else ans = to_string(S+1) + ans;              //first smallest number
        
        int ind = D-1;
        for(int i = D-1;i>=0;i--){
            if(ans[i]=='9'){
                ind = i;
            }
            else{
                break;
            }
        }
        ans[ind]--;
        ans[ind-1]++;
        
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends