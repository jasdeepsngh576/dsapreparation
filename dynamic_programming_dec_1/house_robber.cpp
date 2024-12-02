class Solution {
public:

    /*
        Question link - https://leetcode.com/problems/house-robber/
        
        Recursive relation - 
        Consider f(n, 0) to be maximum money obtainable upto nth house if nth house is robbed 
        and f(n, 1) to be the maximum money obtainable if nth house is not robbed. 

        f(n, 0) = money(n) + f(n-1, 1)
        f(n, 1) = max(f(n-1, 0), f(n-1, 1))



        Time Complexity - O(n) where n is number of houses
        Space Complexity - O(1)

    */

    int rob(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];

        int rob = nums[0];
        int nrob = 0;

        for(int i=1;i<nums.size();i++)
        {
            int rob_new = nums[i] + nrob; 
            int nrob_new = max(rob, nrob);

            rob = rob_new;
            nrob = nrob_new;

        }

        return max(rob, nrob);

    }
};