//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool search(vector<vector<char>>& board,string word,int row,int col,int n,int m,int ptr){
        if(ptr==word.size()) return true;
        int drow[4] = {0,0,1,-1};
        int dcol[4] = {1,-1,0,0};
        char original = board[row][col];
        board[row][col] = '#';
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && board[nrow][ncol]==word[ptr]){
                    return search(board,word,nrow,ncol,n,m,ptr+1);
                
            }
        }
        
        board[row][col] = original;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    bool ans = search(board,word,i,j,n,m,1);
                    //cout<<ans<<" ";
                    if(ans==true) return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends