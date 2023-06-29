//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool isHappy(int n){
        unordered_set<int> st;
        int sum =n;
        
        while(sum!=1){
            int temp = sum;
            int num = 0;
            while(temp>0){
                num +=(temp%10)*(temp%10);
                temp/=10;
            }
            
            if(st.find(num)!=st.end()) return false;
            
            st.insert(num);
            sum = num;
        }
        
        return true;
    }
    int nextHappy(int N){
        
        int num = N+1;
        
        while(true){
            if(isHappy(num)) return num;
            
            num++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends