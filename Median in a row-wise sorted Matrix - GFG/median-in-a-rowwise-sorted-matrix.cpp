//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countSmaller(int mid,vector<vector<int>> &m){
        int n = m.size();
        int count=0;
        
        for(int i=0;i<n;i++){
            count+=(upper_bound(m[i].begin(),m[i].end(),mid) - m[i].begin());
        }
        return count;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        int mini = matrix[0][0];
        int maxi = matrix[R-1][C-1];
        
        for(int i=0;i<R;i++){
            if(matrix[i][0]<mini) mini=matrix[i][0];
            if(matrix[i][C-1]>maxi) maxi = matrix[i][C-1];
        }
        
        int low = mini;
        int high = maxi;
        int n = (R*C)/2;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            
            if(countSmaller(mid,matrix)<=n){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends