//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    /*
    
        Question link - https://www.geeksforgeeks.org/problems/geek-jump/1
        
        Recursive Relation - 
        Consider f(n) to be minimum energy consumed to reach (n-1)th stair
        from 0th stair then
        
        f(n) = min( f(n-1) + abs(height[n-1] - height[n]), f(n-2) + abs(height[n-2] - height[n]))
        
        Time complexity - O(n)
        Space complexity - O(1) (if we ignore the space taken by input)
        
    
    */
  
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        
        if(n == 1)
            return 0;
            
        if(n == 2)
            return abs(height[1] - height[0]);
        
        int f_n_2 = 0;
        int f_n_1 = abs(height[1] - height[0]);
        
        int f_n;
        
        for(int i=2;i<n;i++)
        {
            f_n = min(f_n_1 + abs(height[i-1] - height[i]), f_n_2 + abs(height[i-2] - height[i]));
            f_n_2 = f_n_1;
            f_n_1 = f_n;
        }
        return f_n;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends