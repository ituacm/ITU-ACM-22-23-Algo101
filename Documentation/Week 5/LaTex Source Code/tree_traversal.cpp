#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->value << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->value << " ";
}

int main()
{
    // declaring tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    // preorder traversal
    preorderTraversal(root);
    cout << endl;
    // inorder traversal
    inorderTraversal(root);
    cout << endl;
    // postorder traversal
    postorderTraversal(root);
    cout << endl;

    return 0;
}