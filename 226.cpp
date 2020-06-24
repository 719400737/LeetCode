#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
    void helper(TreeNode* root){
        if(root==NULL)
            return;
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=temp;
        helper(root->left);
        helper(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};

int main(){


    return 0;
}