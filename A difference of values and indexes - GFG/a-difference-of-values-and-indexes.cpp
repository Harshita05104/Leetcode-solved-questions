//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        int max1 = INT_MIN;
        int min1 = INT_MAX;
        int max2 = INT_MIN;
        int min2 = INT_MAX;
        for(int i = 0; i<n;i++){
            if(arr[i]-i>max1){
                max1 = arr[i]-i;
            }
            if(arr[i]-i<min1){
                min1 = arr[i]-i;
            }
            if(arr[i]+i>max2){
                max2 = arr[i]+i;
            }
            if(arr[i]+i<min2){
                min2 = arr[i]+i;
            }
        }
        int ans1 = max1-min1;
        int ans2 = max2-min2;
        int ans = max(ans1,ans2);
        
        return ans;
        
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends