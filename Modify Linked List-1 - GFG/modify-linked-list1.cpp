//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    Node* reverseList(Node* head){
        if(head->next==NULL) return head;
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;
        while(curr!=NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // Mid ko tod diya
        Node* head2 = slow->next;
        slow->next = NULL;
        
        Node* head2Rev = reverseList(head2);
        
        Node* temp1 = head2Rev;
        Node* temp2 = head;
        while(temp1!=NULL){
            temp1->data = temp1->data - temp2->data;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        Node* head1 = reverseList(head);
        
        
        temp1 = head2Rev;
        while(temp1->next!=NULL){
            temp1 = temp1->next;
        }
        
        temp1->next = head1;
        
        return head2Rev;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends