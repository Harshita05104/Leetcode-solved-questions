//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
            int pivot = partition(arr,low,high);
            
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }
    
    public:
    int partition (int a[], int low, int high)
    {
       int pivot = a[low];
       int i=low,j=high;
       while(i<j){
           while(i<=high && a[i]<=pivot) i++;
           while(j>=0 && a[j]>pivot) j--;
           
           if(i<j) swap(a[i],a[j]);
       }
       
       swap(a[j],a[low]);
       return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends