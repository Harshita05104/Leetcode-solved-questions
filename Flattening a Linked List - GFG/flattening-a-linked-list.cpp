//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class Solution {
public:
    Node* merge(Node* head1,Node* head2){
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        
        Node* dummyNode = new Node(-1);
      Node* ptr1 = head1;
      Node* ptr2 = head2;
      Node* ptr3 = dummyNode;
      while(ptr1!=NULL && ptr2!=NULL){
          if(ptr1->data<=ptr2->data){
              ptr3->bottom = ptr1;
              ptr1 = ptr1->bottom;
          }
          else{
              ptr3->bottom = ptr2;
              ptr2=ptr2->bottom;
          }
          ptr3=ptr3->bottom;
      }
      while(ptr1!=NULL){
          ptr3->bottom = ptr1;
          ptr1=ptr1->bottom;
          ptr3=ptr3->bottom;
      }
      while(ptr2!=NULL){
          ptr3->bottom = ptr2;
          ptr2=ptr2->bottom;
          ptr3=ptr3->bottom;
      }
      return dummyNode->bottom;
    }
    Node *flatten(Node *root)
    {
        if(root==NULL || root->next==NULL) return root;
        
        Node* right = flatten(root->next);
        root->next = NULL;
        Node* ans = merge(root,right);
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node * temp = NULL;
        struct Node * head = NULL;
        struct Node * pre = NULL;
        struct Node * tempB = NULL;
        struct Node * preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Solution ob;
        Node* root = ob.flatten(head);
        printList(root);
        cout << endl;

    }
    return 0;
}

// } Driver Code Ends