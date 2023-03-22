//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      long long cost = 0;
      stack<char> st;
      if(X>Y){
          for(int i=0;i<S.size();i++){
              if(!st.empty() && st.top()=='p' && S[i]=='r'){
                  st.pop();
                  cost+=X;
              }
              else{
                  st.push(S[i]);
              }
          }
          stack<char> st2;
          while(!st.empty()){
               if(!st2.empty() && st2.top()=='p' && st.top()=='r'){
                  st2.pop();
                  cost+=Y;
              }
              else{
                  st2.push(st.top());
              }
              st.pop();
          }
      }
      else{
           for(int i=0;i<S.size();i++){
              if(!st.empty() && st.top()=='r' && S[i]=='p'){
                  st.pop();
                  cost+=Y;
              }
              else{
                  st.push(S[i]);
              }
          }
          
          stack<char> st2;
          while(!st.empty()){
               if(!st2.empty() && st2.top()=='r' && st.top()=='p'){
                  st2.pop();
                  cost+=X;
              }
              else{
                  st2.push(st.top());
              }
              st.pop();
          }
          
      }
      return cost;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends