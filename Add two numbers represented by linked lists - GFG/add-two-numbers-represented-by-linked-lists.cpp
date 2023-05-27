//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

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


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
     Node* reverseList(Node* head){
        if(head->next == NULL) return head;
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
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* temp1 = reverseList(first);
        Node* temp2 = reverseList(second);
        int carry = 0;
        Node* Listsum = new Node(-1);
        Node* temp = Listsum;
        while(temp1!=NULL && temp2!=NULL){
            int sum = temp1->data + temp2->data + carry;
            int rem = sum%10;
            carry = sum/10;
            Node* newNode = new Node(rem);
            temp->next = newNode;
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while(temp1!=NULL){
            int sum = carry + temp1->data;
            int rem = sum%10;
            carry = sum/10;
            Node* newNode = new Node(rem);
            temp->next = newNode;
            temp = temp->next;
            temp1 = temp1->next;
        }
        
         while(temp2!=NULL){
            int sum = carry + temp2->data;
            int rem = sum%10;
            carry = sum/10;
            Node* newNode = new Node(rem);
            temp->next = newNode;
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        if(carry>0){
            Node* newNode = new Node(carry);
            temp->next = newNode;
            temp = temp->next;
        }
        
        Node* rev = Listsum->next;
        Listsum->next=NULL;
        free(Listsum);
        
        Node* newHead = reverseList(rev);
        
        return newHead;
    }
};


//{ Driver Code Starts.

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
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends