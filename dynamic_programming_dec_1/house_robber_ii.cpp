class Solution {
public:

    /*

        Question link - https://leetcode.com/problems/house-robber-ii/

        Recursive relation - 
        Consider f(n, 0) to be maximum money obtainable upto nth house if nth house is robbed 
        and f(n, 1) to be the maximum money obtainable if nth house is not robbed. 

        f(n, 0) = money(n) + f(n-1, 1)
        f(n, 1) = max(f(n-1, 0), f(n-1, 1))

        Recursive relation is similar to house robber question. There is slight modification to handle circular 
        case - 
        
        Case 1 - when we rob the first house. In that case f(n, 1) = -1 representing we are always robbing the first house
        In that case we do not consider the last house 

        Case 2 - when we do not rob the first house. In that case f(n, 0) = -1 representing we are never robbing the first house
        In this case we consider both cases when last house is robbed and when it is not. 




        Time complexity - O(n) where n is number of homes
        Space complexity - O(1)

    */


    int rob(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];

        int rob = nums[0];
        int nrob = -1;

        int ans = INT_MIN;

        for(int i=1;i<nums.size() - 1;i++)
        {
            int rob_new = -1;
            int nrob_new = -1;


            if(nrob != -1)
                rob_new = nums[i] + nrob; 
            
            if(nrob != -1 && rob != -1)
              nrob_new = max(rob, nrob);
            else if(rob != -1)
              nrob_new = rob;
            else if(nrob != -1)
              nrob_new = nrob;
            
            rob = rob_new;
            nrob = nrob_new;

        }

        ans = max(rob, nrob);

        rob = -1;
        nrob = 0;

        for(int i=1;i<nums.size();i++)
        {
            int rob_new = -1;
            int nrob_new = -1;


            if(nrob != -1)
                rob_new = nums[i] + nrob; 
            
            if(nrob != -1 && rob != -1)
              nrob_new = max(rob, nrob);
            else if(rob != -1)
              nrob_new = rob;
            else if(nrob != -1)
              nrob_new = nrob;
            
            rob = rob_new;
            nrob = nrob_new;

        }

        ans = max(ans, max(rob, nrob));

        return ans;

        
    }
};