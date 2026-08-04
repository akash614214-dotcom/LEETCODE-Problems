
int minDepth(struct TreeNode* r) {
    if (!r) return 0;
    if (!r->left) return 1 + minDepth(r->right);
    if (!r->right) return 1 + minDepth(r->left);
    
    int l = minDepth(r->left);
    int rt = minDepth(r->right);
    
    return 1 + (l < rt ? l : rt);
}