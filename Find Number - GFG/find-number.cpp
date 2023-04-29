//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long n){
        long long ans =0;
        while(n>0){
            if(n%5==1){
                ans=ans*10 + 1;
                n/=5;
            }
            else if(n%5==2){
                ans=ans*10 + 3;
                n/=5;
            }
             else if(n%5==3){
                ans=ans*10 + 5;
                n/=5;
            }
             else if(n%5==4){
                ans=ans*10 + 7;
                n/=5;
            }
            else{
                ans=ans*10+9;
                n/=5;
                n--;
            }
        }
        
        long long res =0;
        while(ans>0){
            res = res*10 + (ans%10);
            ans/=10;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends