//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    int searchNode(int arr[],int size,int node){
        for(int i=0;i<size;i++){
            if(arr[i]==node) return i;
            
            
        }
        return -1;
    } 
    
    Node* constructTree(int pre[],int preMirror[],int size,int i,int j){
        // base condition
        if(i>j) return NULL;
        
        Node* newNode = new Node(pre[i]);
        if(i==j) return newNode;
        int leftIndex = searchNode(preMirror,size,pre[i]);
        int rightIndex = searchNode(pre,size,preMirror[leftIndex+1]);
        newNode->left = constructTree(pre,preMirror,size,i+1,rightIndex-1);
        newNode->right = constructTree(pre,preMirror,size,rightIndex,j);
        
        return newNode;
    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        return constructTree(pre,preMirror,size,0,size-1);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends