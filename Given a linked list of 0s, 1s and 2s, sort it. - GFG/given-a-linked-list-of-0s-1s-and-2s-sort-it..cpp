//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(head==NULL || head->next==NULL) return head;
        
        Node* zeroHead = new Node(-1);
        Node* temp0 = zeroHead;
        
        Node* oneHead = new Node(-1);
        Node* temp1 = oneHead;
        
        Node* twoHead = new Node(-1);
        Node* temp2 = twoHead;
        
        Node* temp = head;
        
        while(temp!=NULL){
            if(temp->data==0){
                temp0->next = temp;
                temp0 = temp0->next;
            }
            else if(temp->data==1){
                temp1->next = temp;
                temp1 = temp1->next;
            }
            else{
                temp2->next = temp;
                temp2 = temp2->next;
            }
            
            temp = temp->next;
        }
        
        if(oneHead->next!=NULL){
            temp0->next = oneHead->next;
            temp1->next = twoHead->next;
            temp2->next = NULL;
        }
        else{
            temp0->next = twoHead->next;
            temp2->next = NULL;
        }
        head = zeroHead->next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends