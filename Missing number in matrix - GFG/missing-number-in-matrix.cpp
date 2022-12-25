//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool rowSum(vector<vector<int> >& matrix,long long int actual_sum,long long int mis_value){
        int n = matrix.size();
        long long int sum = 0;
        for(int i =0;i<n;i++){
            sum = 0;
            for(int j = 0;j<n;j++){
                if(matrix[i][j]==0){
                    sum+=mis_value;
                }
                else{
                    sum+=matrix[i][j];
                }
            }
            if(sum!=actual_sum) return false;
        }
        
        return true;
    }
    
     bool colSum(vector<vector<int> >& matrix,long long int actual_sum,long long int mis_value){
          int n = matrix.size();
        long long int sum = 0;
        for(int i =0;i<n;i++){
            sum = 0;
            for(int j = 0;j<n;j++){
                if(matrix[j][i]==0){
                    sum+=mis_value;
                }
                else{
                    sum+=matrix[j][i];
                }
            }
            if(sum!=actual_sum) return false;
        }
        
        return true;
    }
    
     bool diagSum(vector<vector<int> >& matrix,long long int actual_sum,long long int mis_value){
        int n = matrix.size();
        long long int sum = 0;
        for(int i=0;i<n;i++){
            if(matrix[i][i]==0){
                sum+=mis_value;
            }
            else{
                sum+=matrix[i][i];
            }
        }
        if(sum!=actual_sum) return false;
        
        sum = 0;
        for(int i= 0;i<n;i++){
            if(matrix[i][n-i-1]==0){
                sum+=mis_value;
            }
            else{
                sum+=matrix[i][n-i-1];
            }
        }
        if(sum!=actual_sum) return false;
        
        return true;
    }
    
    long long int MissingNo(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int row_z=-1,col_z=-1;
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]==0){
                    row_z = i;
                    col_z = j;
                    flag = true;
                }
            }
            if(flag==true) break;
        }
        long long int zero_sum = 0,actual_sum=0;
        if(row_z==0){
            for(int i = 0;i<n;i++){
                zero_sum+=matrix[0][i];
            }
            for(int i = 0;i<n;i++){
                actual_sum+=matrix[1][i];
            }
        }
        else{
            for(int i = 0;i<n;i++){
                actual_sum+=matrix[0][i];
            }
            for(int i = 0;i<n;i++){
                zero_sum+=matrix[row_z][i];
            }
        }
        
        long long int mis_value = (actual_sum - zero_sum);
        if(mis_value<=0) return -1;
        
        if(rowSum(matrix,actual_sum,mis_value) && colSum(matrix,actual_sum,mis_value) && 
        diagSum(matrix,actual_sum,mis_value)){
            return mis_value;
        }
        else{
            return -1;
        }
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends