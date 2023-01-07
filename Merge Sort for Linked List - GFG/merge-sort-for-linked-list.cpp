//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  //Function to find middle of a given linked list
  Node* findMid(Node* head){
      if(head==NULL) return NULL;
      
      Node* slow=head;
      Node* fast=head;
      while(fast->next!=NULL && fast->next->next!=NULL){
          slow=slow->next;
          fast = fast->next->next;
      }
      
      return slow;
  }
  
  Node* merge(Node* head1,Node* head2){
      if(head1==NULL) return head2;
      if(head2==NULL) return head1;
      
      Node* dummyNode = new Node(-1);
      Node* ptr1 = head1;
      Node* ptr2 = head2;
      Node* ptr3 = dummyNode;
      while(ptr1!=NULL && ptr2!=NULL){
          if(ptr1->data<=ptr2->data){
              ptr3->next = ptr1;
              ptr1 = ptr1->next;
          }
          else{
              ptr3->next = ptr2;
              ptr2=ptr2->next;
          }
          ptr3=ptr3->next;
      }
      while(ptr1!=NULL){
          ptr3->next = ptr1;
          ptr1=ptr1->next;
          ptr3=ptr3->next;
      }
      while(ptr2!=NULL){
          ptr3->next = ptr2;
          ptr2=ptr2->next;
          ptr3=ptr3->next;
      }
      return dummyNode->next;
  }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        
        Node* mid = findMid(head);
        Node* midNext = mid->next;
        mid->next=NULL;
        
        Node* temp1 = mergeSort(head);
        Node* temp2 = mergeSort(midNext);
        
        Node* ans = merge(temp1,temp2);
        return ans;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends