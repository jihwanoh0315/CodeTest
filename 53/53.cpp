/*
* Name: Jihwan Oh
* e-mail: jihwanoh315@gmail.com
*
* 53. Maximum Subarray
* https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150
*/


/*

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currLargeSum = nums[0];
        int currSum = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(currSum < 0)
            {
                currSum = 0;
            }

            currSum += nums[i];
            
            if(currSum > currLargeSum)
            {
                currLargeSum = currSum;
            }
        }

        return currLargeSum;
    }
};