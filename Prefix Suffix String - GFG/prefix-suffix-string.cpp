//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Node{
    public:
    Node* links[26];
    
    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
    }
    
};

class Trie{
    public:
    Node* root;
    
    Trie(){
        root = new Node();
    }
    
    void insert(string str){
        Node* temp = root;
        for(int i=0;i<str.size();i++){
            if(temp->links[str[i]-'a']==NULL){
                Node* newNode = new Node();
                temp->links[str[i]-'a'] = newNode;
                temp = temp->links[str[i]-'a'];
            }
            else{
                temp = temp->links[str[i]-'a'];
            }
        }
    }
    
    bool search(string str){
        Node* temp = root;
        for(int i=0;i<str.size();i++){
            if(temp->links[str[i]-'a']!=NULL){
                temp = temp->links[str[i]-'a'];
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};
class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        Trie* t = new Trie();
        for(int i=0;i<s1.size();i++){
            t->insert(s1[i]);
            reverse(s1[i].begin(),s1[i].end());
            t->insert(s1[i]);
        }
        
        int count = 0;
        for(int i=0;i<s2.size();i++){
            string str1 = s2[i];
            reverse(s2[i].begin(),s2[i].end());
            string str2 = s2[i];
            if(t->search(str1) || t->search(str2)){
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends