//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool isPrime(int x){
        if(x==1) return false;
        if(x==2 || x==3) return true;
        
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
    Node *primeList(Node *head){
        Node* cur = head;
        while(cur!=NULL){
            if(cur->val==1){
                cur->val = 2;
                cur = cur->next;
            }
            else{
                int x = cur->val;
                int y = cur->val;
                while(!isPrime(x)){
                    x--;
                }
                while(!isPrime(y)){
                    y++;
                }
                
                if(cur->val-x > y-cur->val){
                    cur->val = y;
                }
                else{
                    cur->val = x;
                }
                
                cur = cur->next;
            }
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends