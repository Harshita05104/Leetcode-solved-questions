//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverseList(Node* head){
        if(head->next==NULL) return head;
        
        Node* cur = head;
        Node* prev = NULL;
        Node* nextNode = NULL;
        
        while(cur!=NULL){
            nextNode = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = nextNode;
        }
        
        return prev;
    }
    Node *compute(Node *head)
    {
        if(head->next==NULL) return head;
        Node* revHead = reverseList(head);
        
        Node* temp = revHead->next;
        int maxi = revHead->data;
        Node* prev = revHead;
        
        while(temp!=NULL){
            maxi = max(temp->data,maxi);
            if(temp->data<maxi){
                temp = temp->next;
            }
            else{
                prev->next = temp;
                prev = temp;
                temp = temp->next;
            }
        }
        
        prev->next = NULL;
        
        Node* ans = reverseList(revHead);
        
        return ans;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends