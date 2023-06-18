//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int K) {
        int st=1,end=n;
        bool flag = true;
        int Ttime = 0;
        while(st<end){
            if(flag==true){
                while(st<end && Ttime<K){
                    st++;
                    Ttime++;
                }
            }
            else{
                while(st<end && Ttime<K){
                    end--;
                    Ttime++;
                } 
            }
            Ttime = 0;
            flag = !flag;
        }
        
        return st;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends