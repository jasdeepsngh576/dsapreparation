//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    /*
        Question Link - https://www.geeksforgeeks.org/problems/rod-cutting0840/1

        Recursive relation
        
        Let f(n) be maximum value obtainable from rod of length n

        then f(n) = max( f(1) + f(n-1) , f(2) + f(n-2), f(3) + f(n-3) ...  )
        
        
        Time Complexity - O(n^2)
        Space Complexity - O(n)
    
    */
  
    int cutRod(vector<int> &price) {
        // code here
        
        int n = price.size();
        
        vector<int> dp(n+1);
        dp[0] = 0;
        
        int max_ans = 0;
        

        
        for(int i=1; i < dp.size(); i++)
        {
            dp[i] = price[i-1]; 
            for(int j=1;j<=i/2;j++)
            {
                dp[i] = max(dp[i], price[j-1] + dp[i-j]);
            }
            max_ans = max(max_ans, dp[i]);
        }
        
        return max_ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends