//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        int i=0;
        int j=0;
        int n = matrix.size();
        int m = matrix[0].size();
        char dir = 'r';
        while(i<n && j<m && i>=0 && j>=0){
            if(dir == 'r'){
                if(matrix[i][j]==0){
                    j++;
                }else{
                    matrix[i][j]= 0;
                    i++;
                    dir = 'd';
                }
            }
            else if(dir == 'u'){
                  if(matrix[i][j]==0){
                    i--;
                }else{
                    matrix[i][j]= 0;
                    j++;
                    dir = 'r';
                }
            }
            else if(dir == 'l'){
                  if(matrix[i][j]==0){
                    j--;
                }else{
                    matrix[i][j]= 0;
                    i--;
                    dir = 'u';
                }
            }
            else if(dir == 'd'){
                  if(matrix[i][j]==0){
                    i++;
                }else{
                    matrix[i][j]= 0;
                    j--;
                    dir = 'l';
                }
            }
            
            //cout<<i<<" "<<j<<" ";
        }
        
        if(dir=='r'){
            return {i,j-1};
        }
        if(dir=='u'){
            return {i+1,j};
        }
        if(dir=='l'){
            return {i,j+1};
        }
        if(dir=='d'){
            return {i-1,j};
        }
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends