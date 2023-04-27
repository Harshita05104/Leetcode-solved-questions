//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    char solve(int freq[],int k){
        int count = 0;
        for(int i=25;i>=0;i--){
            count+=freq[i];
            if(count>=k){
                return i+'a';
            }
        }
        return '0';
    }
    vector<char> easyTask(int n,string s,int qu,vector<vector<string>> &q){
        vector<char> ans;
        for(int i=0;i<qu;i++){
            //type 1 query
            if(q[i].size()==3){
                int ind = stoi(q[i][1]);
                s[ind] = q[i][2][0];
            }
            //type 2 query
            else{
                int left = stoi(q[i][1]);
                int right = stoi(q[i][2]);
                int k = stoi(q[i][3]);
        
                int freq[26] = {0};
                for(int j=left;j<=right;j++){
                    freq[s[j]-'a']++;
                }
                char ch = solve(freq,k);
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends