//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    /* 
    
        Question link - https://www.geeksforgeeks.org/problems/minimal-cost/1
        
        Recursive Relation - 
        Let f(n) be the minimum cost to reach nth stone 
        
        f(n) = min( f(n-1) + |h(n) - h(n-1)| , f(n-2) + |h(n) - h(n-2) | ..... f(n-k) + |h(n) - h(n-k) |)
        
        
        Time Complexity - O(n*k)
        Space Complexity - O(k)
    
    */
    
    
  
    int minimizeCost(int k, vector<int>& arr) {
        
        int n = arr.size();
        
        if(n == 1)
            return 0;
        

        deque<int> dp;
        dp.push_back(0);
        
        
        for(int i=1;i<n;i++)
        {
            dp.push_back(INT_MAX);
            //int dq_size = dp.size();
            int size = dp.size();
            int index = 1;
            
            for(int j=size-2;j>=0;j--)
            {
                dp[size-1] = min(dp[size-1], dp[j] + abs(arr[i] - arr[i-index]));
                index++;
            }

            
            if(dp.size() > k)
                dp.pop_front();
            
        }
        
        return dp[dp.size()-1];
    
        // Code here
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends