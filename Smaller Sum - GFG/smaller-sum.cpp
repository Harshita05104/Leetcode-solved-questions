//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<int> dup(n);
        for(int i=0;i<arr.size();i++){
            dup[i] = arr[i];
        }
        
        sort(dup.begin(),dup.end());
        long long sum = 0;
        vector<long long> ans;
        unordered_map<int,long long> mp;
        for(int i=0;i<n;i++){
            if(mp.find(dup[i])==mp.end()){
                mp[dup[i]] = sum;
            }
            sum+=dup[i];
        }
        
        for(int i=0;i<arr.size();i++){
            ans.push_back(mp[arr[i]]);
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends