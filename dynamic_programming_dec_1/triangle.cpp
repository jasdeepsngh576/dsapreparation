class Solution {
public:

    /* 
        Question link - https://leetcode.com/problems/triangle/

        Recursive relation - 
        Let f(n, k) be the minimum path sum required to reach kth element of nth row from top
        f(n, k) = Cost(n, k) + min( f(n-1, k) , f(n-1, k-1) )

        Time Complexity - O(n^2) where n is number of rows in triangle
        space complexity - O(n)
    
    */    

    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<int> dp(1);
        dp[0] = triangle[0][0];

        for(int i=1;i<triangle.size();i++)
        {
            vector<int> curr(i+1);
            curr[0] = dp[0] + triangle[i][0];
            curr[i] = dp[i-1] + triangle[i][i];

            for(int j=1;j<i;j++)
            {
                curr[j] = triangle[i][j] + min(dp[j], dp[j-1]); 
            }

            dp = curr;

        }

        return *min_element(dp.begin(), dp.end());

    }
};