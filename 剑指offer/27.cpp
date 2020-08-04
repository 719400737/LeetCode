#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void helper(TreeNode* root){
        if(root==NULL)
            return;
        TreeNode* cur=root->right;
        root->right=root->left;
        root->left=cur;
        helper(root->right);
        helper(root->left);
    }
public:
    TreeNode* mirrorTree(TreeNode* root) {
        helper(root);
        return root;    
    }
};
int main(){



    return 1;
}