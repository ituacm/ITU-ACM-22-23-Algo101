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

vector<int> numbers = {4, 1, 2, 6, 3, 9, 7, 8, 5};

TreeNode* recursiveBSTgen(vector<int>& numbers, int left, int right)
{
    // When there is no element to place
    if(left > right)
    {
        return NULL;
    }
    int middle = (left + right) / 2;
    TreeNode* root = new TreeNode(numbers[middle]);
    // left and right branches
    root->left = recursiveBSTgen(numbers, left, middle - 1);
    root->right = recursiveBSTgen(numbers, middle + 1, right);        
    return root;
}

int main()
{
    sort(numbers.begin(), numbers.end());
    TreeNode* balancedBST = recursiveBSTgen(numbers, 0, numbers.size() - 1);
    return 0;
}
