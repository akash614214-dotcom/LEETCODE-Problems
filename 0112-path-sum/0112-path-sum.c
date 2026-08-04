/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>

bool hasPathSum(struct TreeNode* r, int t) {
    if (!r) return false;
    if (!r->left && !r->right) return t == r->val;
    
    return hasPathSum(r->left, t - r->val) || hasPathSum(r->right, t - r->val);
}
