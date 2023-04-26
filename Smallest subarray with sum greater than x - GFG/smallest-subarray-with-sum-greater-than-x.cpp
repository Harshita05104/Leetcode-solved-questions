//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int start = 0,end=0,sum = arr[0],mini=n;
        while(start<n && end<n){
            if(sum<=x){
                end++;
                if(end<n) sum+=arr[end];
            }
            else{
                mini = min(end-start+1,mini);
                sum-=arr[start];
                start++;
            }
        }
        
        return mini;
        
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends