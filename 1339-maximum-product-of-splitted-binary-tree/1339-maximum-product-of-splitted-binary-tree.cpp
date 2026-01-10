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
    long long MOD = 1e9 + 7;

    long long stsum(TreeNode* root){
        if(!root) return 0;
        return root->val + stsum(root->left) + stsum(root->right);
    }

    long long dfs(TreeNode* root, long long ts, long long &maxprod  ){
        if(!root) return 0;

        long long left = dfs(root->left, ts, maxprod);
        long long right = dfs(root->right, ts, maxprod);

        long long currsum = root->val + left + right;
        long long rmsum = ts - currsum;

        maxprod = max(maxprod, currsum * rmsum);

        return currsum;
    }


    int maxProduct(TreeNode* root) {

        long long ts  = stsum(root);

        long long maxprod = 0;

        dfs(root, ts, maxprod);

        return maxprod % MOD; 


        
    }
};