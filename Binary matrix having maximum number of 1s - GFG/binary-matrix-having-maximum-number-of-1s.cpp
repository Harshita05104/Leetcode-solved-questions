//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        vector<int> count;
        int ind_r= 0;
        int ind_c = 0;
        bool flag = false;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mat[j][i]==1){
                    flag = true;
                    ind_r = j;
                    ind_c =i;
                    break;
                }
            }
            if(flag==true) break;
        }
        if(flag==false){
            count.push_back(0);
            count.push_back(0);
        }
        else{
             count.push_back(ind_r);
            count.push_back(N-ind_c);
        }
        
       
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends