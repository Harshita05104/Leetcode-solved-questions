//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        vector<int> left,right,ans;
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                left.push_back(-1);
            }
            else{
                left.push_back(st.top());
            }
            
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=arr.size()-1;i>=0;i--){
             while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                right.push_back(-1);
            }
            else{
                right.push_back(st.top());
            }
            
            st.push(i);
        }
        
        reverse(right.begin(),right.end());
        
        // for(int i=0;i<arr.size();i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<arr.size();i++){
        //     cout<<right[i]<<" ";
        // }
        // cout<<endl;
        
        for(int i=0;i<arr.size();i++){
            if(left[i]==-1 && right[i]==-1){
                ans.push_back(-1);
            }
            else if(left[i]==-1){
                ans.push_back(right[i]);
            }
            else if(right[i]==-1){
                ans.push_back(left[i]);
            }
            else{
                if(i-left[i]<right[i]-i){
                    ans.push_back(left[i]);
                }
                else if(i-left[i]>right[i]-i){
                    ans.push_back(right[i]);
                }
                else{
                    if(arr[left[i]]!=arr[right[i]]){
                        if(arr[left[i]]<arr[right[i]]){
                            ans.push_back(left[i]);
                        }
                        else{
                            ans.push_back(right[i]);
                        }
                    }
                    else{
                        ans.push_back(min(left[i],right[i]));
                    }
                }
                
            }
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends