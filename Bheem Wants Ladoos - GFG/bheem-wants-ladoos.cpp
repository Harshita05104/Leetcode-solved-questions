//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    int ladoos(Node* root, int home, int k)
    {
        int sum = 0;
        Node* src = NULL;
        unordered_map<Node*,Node*> parent;
        unordered_map<Node*,bool> vis;
        parent[root] = NULL;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                auto front = q.front();
                if(front->data==home){
                    src = front;
                }
                vis[front] = false;
                q.pop();
                if(front->left!=NULL){
                    q.push(front->left);
                    parent[front->left] = front;
                }
                if(front->right!=NULL){
                    q.push(front->right);
                    parent[front->right] = front;
                }
            }
        }
        
        q.push(src);
        vis[src] = true;
        while(!q.empty() && k>0){
            int sz = q.size();
            k--;
            for(int i=0;i<sz;i++){
                auto front = q.front();
                sum+=front->data;
                q.pop();
                if(front->left!=NULL && vis[front->left]==false){
                    q.push(front->left);
                    vis[front->left] = true;
                }
                if(front->right!=NULL && vis[front->right]==false){
                    q.push(front->right);
                    vis[front->right] = true;
                }
                if(parent[front]!=NULL && vis[parent[front]]==false){
                    q.push(parent[front]);
                    vis[parent[front]] = true;
                }
            }
        }
        
        while(!q.empty()){
            auto front = q.front();
            sum +=front->data;
            //cout<<front->data<<" ";
            q.pop();
        }
        
        return sum;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends