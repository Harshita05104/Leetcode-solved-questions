//{ Driver Code Starts
#include <bits/stdc++.h>

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

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
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

/*  Function which returns the  root of 
    the flattened linked list. */
Node* mergeLL(Node* root,Node* temp){
    if(root==NULL) return temp;
    if(temp==NULL) return root;
    
    Node* temp1 = root;
    Node* temp2 = temp;
    Node* temp3 = new Node(-1);
    Node* res = temp3;
    
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<=temp2->data){
            temp3->bottom = temp1;
            temp1=temp1->bottom;
        }
        else{
            temp3->bottom = temp2;
            temp2=temp2->bottom;
        }
        temp3=temp3->bottom;
    }
    while(temp1!=NULL){
        temp3->bottom = temp1;
        temp1=temp1->bottom;
        temp3 = temp3->bottom;
    }
      while(temp2!=NULL){
        temp3->bottom = temp2;
        temp2=temp2->bottom;
        temp3 = temp3->bottom;
    }
    return res->bottom;
}
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL){
       return root;
   }
   
   Node* temp = flatten(root->next);
   root->next=NULL;
   Node* ans = mergeLL(root,temp);
   return ans;
}

