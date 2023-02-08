//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<long long int> ans;
      vector<bool> row1(n,false);
      vector<bool> col1(n,false);
      int row_count = 0;
      int col_count = 0;
      long long int totalZero = n*n;
      for(int i=0;i<k;i++){
          int r = arr[i][0];
          int c = arr[i][1];
          
          if(row1[r-1]==false){
              totalZero = totalZero - (n - col_count);
              row_count++;
              row1[r-1] = true;
          }
          
          if(col1[c-1]==false){
              totalZero = totalZero - (n-row_count);
              col_count++;
              col1[c-1] = true;
          }
          
          ans.push_back(totalZero);
      }
      
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends