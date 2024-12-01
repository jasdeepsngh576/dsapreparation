class Solution {
public:

    /*

        Question link - https://leetcode.com/problems/climbing-stairs/

        Recursive relation - 
        consider f(n) to be number of distinct ways to reach nth step

        then last step to reach f(n) could be 1 step from f(n-1) or 2 steps from
        f(n-2)

        f(n) = f(n-1) + f(n-2)

        Time complexity - O(n)
        Space complexity - O(1)

    */

    int climbStairs(int n) {

        if( n == 1)
            return 1;

        int f_n_1 = 1;
        int f_n_2 = 1;
        int f_n;
        for(int i=2;i<=n;i++)
        {
            f_n = f_n_1 + f_n_2;
            f_n_2 = f_n_1;
            f_n_1 = f_n;
        }
        return f_n;

    }
};