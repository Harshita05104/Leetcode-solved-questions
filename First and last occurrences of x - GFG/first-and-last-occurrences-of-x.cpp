//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int low = 0;
    int high = n-1;
    int mid = low + (high-low)/2;
    int lans = -1;
    int rans = -1;
    //for left occurence
    while(low<=high){
        if(arr[mid]==x){
            lans = mid;
            high = mid-1;
        }
        else if(arr[mid]>x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        mid = low + (high-low)/2;
    }
    //for right occurence
    low = 0;
    high = n-1;
    mid = low + (high-low)/2;
    while(low<=high){
        if(arr[mid]==x){
            rans = mid;
            low = mid+1;
        }
        else if(arr[mid]>x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        mid = low + (high-low)/2;
    }
    
    vector<int> ans;
    ans.push_back(lans);
    ans.push_back(rans);
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends