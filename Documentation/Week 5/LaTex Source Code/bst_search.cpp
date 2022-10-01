#include <bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* root = new TreeNode(4);

int BSTsearch(TreeNode* node, int target, int previous_level)
{
    if(node == NULL)
        return -1; // Invalid level or false,
    if(node->val == target)
        return previous_level + 1; // Current level or true,
    if(node->val > target)
        return BSTsearch(node->left, target, previous_level + 1);
    if(node->val < target)
        return BSTsearch(node->right, target, previous_level + 1);
}
// Function call
int level = BSTsearch(root, 9, 0);