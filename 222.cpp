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
    
    int helper(TreeNode* root){//暴力遍历
        if(root==NULL)
            return 0;
        return 1+helper(root->left)+helper(root->right);
    }
    
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        helper(root);
        return res;
    }
};

int main(){


    return 0;
}