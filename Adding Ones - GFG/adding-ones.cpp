//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    void update(int a[], int n, int updates[], int k)
    {
        int j=1;
        int count=0;
        sort(updates,updates+k);
        for(int i=0;i<k;i++){
            while(j<=n && updates[i]!=j){
                j++;
                a[j-1] = count;
            }
            count++;
            a[j-1] = count;
        }
        
        for(int l=j;l<=n;l++){
            a[l-1] = count;
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n]={0}, updates[k]={0};
		for(int i = 0; i < k; i++)
		cin>>updates[i];
		Solution ob;
		ob.update(a, n, updates, k);
		
		for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
		
		cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends