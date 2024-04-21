/*
* Name: Jihwan Oh
* e-mail: jihwanoh315@gmail.com
*
* 209. Minimum Size Subarray Sum
* https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150
*/


/*

    Example 1:

    Input: target = 7, nums = [2,3,1,2,4,3]
    Output: 2
    Explanation: The subarray [4,3] has the minimal length under the problem constraint.
    Example 2:

    Input: target = 4, nums = [1,4,4]
    Output: 1
    Example 3:

    Input: target = 11, nums = [1,1,1,1,1,1,1,1]
    Output: 0

*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int begin = 0;
        int end = 0;
        int length = 0;
        int minLength = INT_MAX;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[end++];
            ++length;
            while (sum >= target)
            {
                if (length < minLength)
                {
                    minLength = length;
                }
                --length;
                sum -= nums[begin++];
            }
        }

        if (minLength == INT_MAX)
            return 0;

        return minLength;
    }
};