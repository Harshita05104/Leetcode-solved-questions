//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        int ans = 0;
        int start = 0;
        int end = str.size()-1;
        while(start<=end){
            if(str[start]!=str[end]){
                start = 0;
                end = str.size()-ans-2;
                ans++;
            }
            else{
                start++;
                end--;
            }
        }
        
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
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends