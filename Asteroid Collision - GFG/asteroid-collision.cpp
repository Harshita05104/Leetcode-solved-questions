//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> s;
        for(int i = 0;i<asteroids.size();i++){
            if(s.empty() || asteroids[i]>0){
                s.push(asteroids[i]);
            }
            else{
                int flag = 0;
                while(flag==0){
                if(s.top()<0){
                    s.push(asteroids[i]);
                    flag=1;
                }
                else{
                    if(s.top()==abs(asteroids[i])){
                        s.pop();
                        flag=1;
                    }
                    else if(s.top()>abs(asteroids[i])){
                        flag = 1;
                    }
                    else{
                        s.pop();
                        if(s.empty()){
                            s.push(asteroids[i]);
                            flag = 1;
                        }
                    }
                }
                }
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends