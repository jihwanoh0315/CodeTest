/*
* Name: Jihwan Oh
* e-mail: jihwanoh315@gmail.com
* 
* 108. Convert Sorted Array to Binary Search Tree
* https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Divider(int left, int right, vector<int>& nums)
    {
        if (left > right)
            return nullptr;

        int midVal = (left + right) / 2;

        TreeNode* curRoot = new TreeNode(nums[midVal]);
        curRoot->left = Divider(left, midVal - 1, nums);
        curRoot->right = Divider(midVal + 1, right, nums);
        return curRoot;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Divider(0, nums.size() - 1, nums);
    }
};