//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

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
class Solution
{
    public:
    Node* merge(Node* head1,Node* head2){
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        
        Node* nN = new Node(-1);
        Node* temp = nN;
        
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data < temp2->data){
                temp->next = temp1;
                temp1 = temp1->next;
                temp = temp->next;
            }
            else if(temp2->data<temp1->data){
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
            }
            else if(temp1->data == temp2->data){
                temp->next = temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
                temp = temp->next;
            }
        }
        
        while(temp1!=NULL){
            temp->next = temp1;
            temp= temp->next;
            temp1 = temp1->next;
        }
        
        while(temp2!=NULL){
            temp ->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return nN->next;
    }
    
    Node* midof(Node* head){
        
        if(head==NULL || head->next==NULL) return head;
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* mergeSort(Node* head1){
        if(head1==NULL || head1->next==NULL) return head1;
        
        
        Node* mid = midof(head1);
        
        Node* slow=head1;
        Node* fast = mid->next;
        
        mid->next = NULL;
        
        Node* ans1 = mergeSort(slow);
        Node* ans2 = mergeSort(fast);
        
        Node* ans = merge(ans1,ans2);
        
        return ans;
        
    }
    
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        Node* merged1 = mergeSort(head1);
        Node* merged2 = mergeSort(head2);
        
        Node* ans = merge(merged1,merged2);
        
        return ans;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends